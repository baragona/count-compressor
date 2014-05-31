#!/usr/bin/perl -w

use strict;

use Data::Dumper;

use JSON::XS;
use Digest::MD5 qw(md5_base64 md5);
use Cwd;
use count;
use List::Util qw(max sum);
use Storable qw(store_fd nstore_fd freeze thaw);

my $check_sum=1;
my $operating_mode='c';


my ($index_file, $binary_file, $binary2_file) = @ARGV;

$^F = 255; #Allow extra file descriptors to be inherited

open INDEX, "<",  $index_file or die "cant open:$!";
#open my $BINARY, "<",  $binary_file or die "cant open:$!";
open my $BINARY, "-|",  "bzcat $binary_file.bz2" or die "cant open:$!";
open my $BINARY2, "<",  $binary2_file or die "cant open:$!";
#open my $BINARY2, "-|",  "xzcat $binary2_file.xz" or die "cant open:$!";
$/ = undef;
my $index=eval <INDEX> or die "cant eval index: $@";
close INDEX;


#print Dumper $index;

#my @col_to_sorted_keys = @{$index->{col_to_sorted_keys}};
my $n_cols = $index->{n_cols};
my @column_encodings = @{$index->{column_encodings}};
my @col_to_max_length = @{$index->{col_to_max_length}};
my %field_names = %{$index->{field_names}};
my %field_name_to_col = map { $field_names{$_} => $_} keys %field_names;

my @col_to_alphabet = @{$index->{col_to_alphabet}};

my %col_to_predicted_cols = %{$index->{col_to_predicted_cols}};
my @predictor_cols = @{$index->{predictor_cols}};
my $driving_column = $index->{driving_column};
my $driving_col_rice_bits = $index->{driving_col_rice_bits};

my @col_to_max_stored_vals = @{$index->{col_to_max_stored_vals}};

my $max_stored_vals = sum @col_to_max_stored_vals;

my $correct_rows_sum = $index->{rows_sum};
my $correct_n_rows = $index->{n_rows};

#warn Dumper \@predictor_cols;
#warn Dumper \%field_name_to_col;
#exit;

my @col_to_literal_bits;
my @col_to_alpha_idx_to_char;

for (my $c=0;$c<$n_cols;$c++){
    if(defined $col_to_alphabet[$c]){
        $col_to_literal_bits[$c]=count::log2_int(length($col_to_alphabet[$c])-1);

        $col_to_alpha_idx_to_char[$c] = [map {$_} (split //, $col_to_alphabet[$c])];
    }
}

if($operating_mode eq 'perl'){

    #warn Dumper \@col_to_alpha_idx_to_char; exit;

    my @col_to_stored_vals;

    my @previous_row;
    my %col_to_value_to_friends_str_to_count;
    my %col_to_value_to_most_popular_friends;
    my %col_to_friends_str_to_count;
    my %col_to_most_popular_friends;
    my @col_to_ref_count;
    my @col_to_ref_sum;

    my $rows_sum=0;

    my %bitstring_buffers;
    my %total_bits_reads;
    sub read_bits{
        my $stream=shift;
        my $n_bits=shift;

        my $bitstring_buffer = $bitstring_buffers{$stream};
        $bitstring_buffer = '' unless defined $bitstring_buffer;
        my $total_bits_read = $total_bits_reads{$stream};
        $total_bits_read = 0 unless $total_bits_read;

        if($n_bits > length($bitstring_buffer)){
            my $n_bits_to_read = $n_bits - length($bitstring_buffer);
            my $n_bytes = int($n_bits_to_read/8);
            $n_bytes++ if $n_bits_to_read % 8;

            my $data_read;
            read($stream, $data_read, $n_bytes) == $n_bytes or die "Couldn't read enough data.";
            $bitstring_buffer .= count::bytes_to_bitstring($data_read);
        }

        my $bits_to_return = substr($bitstring_buffer, 0, $n_bits);
        $bitstring_buffer = substr($bitstring_buffer, $n_bits);
        $total_bits_read += length($bits_to_return);

        $bitstring_buffers{$stream}=$bitstring_buffer;
        $total_bits_reads{$stream}=$total_bits_read;


        return $bits_to_return;
    }

    sub stream_finished{
        my $stream=shift;
        my $bitstring_buffer = $bitstring_buffers{$stream};
        $bitstring_buffer = '' unless defined $bitstring_buffer;
        return 0 if length($bitstring_buffer);

        my $byte;
        my $n_read = read($stream, $byte, 1);

        if($n_read){
            $bitstring_buffer .= count::bytes_to_bitstring($byte);
            $bitstring_buffers{$stream}=$bitstring_buffer;
            return 0;
        }else{
            return 1;
        }

    }

    sub seek_till_byte_boundary{
        my $stream=shift;
        my $total_bits_read = $total_bits_reads{$stream};
        $total_bits_read = 0 unless $total_bits_read;
        read_bits($stream, 8-($total_bits_read %8)) if ($total_bits_read %8)>0;
    }

#     my $x=0;
#     my $y=0;
#
#
#     while(1){
#         if(!stream_finished($BINARY)){
#             $x+= read_bits($BINARY,1);
#         }
#         if(!stream_finished($BINARY2)){
#             $y+= read_bits($BINARY2,1);
#         }
#         if(stream_finished($BINARY) && stream_finished($BINARY2)){
#             printf("%f\t%f\n", $x, $y);
#             exit(0);
#         }
#     }

    my $r=0;
    while(not stream_finished($BINARY)){


        my %col_was_predicted;
        my %predictor_column_used;
        for my $ceez(@predictor_cols){

            #check if you needed to store a predictor used bit. if everything it would have predicted is already predicted, there is no need.
            my $need_predictor_bit=0;
            my @predicted_cols = @{$col_to_predicted_cols{$ceez}};
            CC: for my $cc(@predicted_cols){
                if(not $col_was_predicted{$cc}){
                    $need_predictor_bit=1;
                    last CC;
                }
            }
            if($need_predictor_bit){
                my $predictor_bit = read_bits($BINARY,1);
                #warn "$predictor_bit\n";
                if($predictor_bit){
                    #predicted
                    $predictor_column_used{$ceez}=1;
                    my $ci=0;
                    for my $cc(@predicted_cols){
                        $col_was_predicted{$cc}=1;


                        $ci++;
                    }
                }else{
                    #not predicted
                }
            }else{
                #warn "dont need predictor $c";
            }
        }

        my @vals;


        my @copy_bits;
        my @encoding_choice_bits;
        my @do_store_bits;

        my $encoding_list='';

        for (my $c=0;$c<$n_cols;$c++){
            next if $col_was_predicted{$c};

            my $copy_bit = read_bits($BINARY,1);
            $copy_bits[$c]=$copy_bit;

            $encoding_list .= "COPY  " if $copy_bit;;

            if($copy_bit != 1){
                $encoding_choice_bits[$c] = read_bits($BINARY,1);
                if($encoding_choice_bits[$c]){
                    $do_store_bits[$c]=read_bits($BINARY,1);
                }

                if($encoding_choice_bits[$c]){
                    $encoding_list .= "LIT-$do_store_bits[$c] ";
                }else{
                    $encoding_list .= "REF   ";
                }
            }
        }

        #warn "ROW $r: $encoding_list\n";

        seek_till_byte_boundary($BINARY);

        my @literal_lengths;

        for (my $c=0;$c<$n_cols;$c++){
            next if $col_was_predicted{$c};


            if($encoding_choice_bits[$c]){
                if($c == $driving_column and $r!=0){
                #only encode the difference
                }else{
                    my $length_length = count::log2_int($col_to_max_length[$c]);
                    $literal_lengths[$c] = read_bits($BINARY,$length_length);
                }
            }
        }

        my $dupes=1;
        while(read_bits($BINARY,1)==1){
            $dupes++;
        }


        seek_till_byte_boundary($BINARY);

        for (my $c=0;$c<$n_cols;$c++){
            my $val;

            if($col_was_predicted{$c}){
                #warn "skipping reading col $c";
            }else{

                #CURRENT CHOICES:
                # 0 - Use stored value
                # 1 - Use Literal value, add to store

                my $copy_bit = $copy_bits[$c];
                if($copy_bit == 1){
                    $val = $previous_row[$c];
                    die "WTF on col $c, row $r\n" unless defined $val;
                }else{

                    my $encoding_choice_bit = $encoding_choice_bits[$c];

                    if($encoding_choice_bit==0){
                        #my $stored_value_length = count::log2_int($#{$col_to_stored_vals[$c]});
                        #my $stored_val_bits = read_bits($BINARY2,$stored_value_length);
                        #my $stored_val_idx = oct("0b$stored_val_bits");

                        my $rice_bits = ($col_to_ref_count[$c] and $col_to_ref_sum[$c]) ?
                            count::log2_int(int(($col_to_ref_sum[$c]+$#{$col_to_stored_vals[$c]})/($col_to_ref_count[$c]+1)))-1
                             : count::log2_int(int(($#{$col_to_stored_vals[$c]}+1)/2))-1;
                        $rice_bits = 0 if $rice_bits < 0;
                        my $stored_val_idx = count::from_rice(sub {read_bits($BINARY2,1)}, $rice_bits);
                        $val = $col_to_stored_vals[$c]->[$stored_val_idx];


                        my $swap_with = int((20*$stored_val_idx) / 21);

                        if($swap_with >= 0 and $swap_with != $stored_val_idx){
                            my $temp = $col_to_stored_vals[$c]->[$stored_val_idx];

                            $col_to_stored_vals[$c]->[$stored_val_idx]=$col_to_stored_vals[$c]->[$swap_with];
                            $col_to_stored_vals[$c]->[$swap_with]=$temp;

                        }


                        $col_to_ref_sum[$c]+=$stored_val_idx;
                        $col_to_ref_count[$c]++;


                    }elsif($encoding_choice_bit==1){
                        if($c == $driving_column and $r!=0){
                            #only encode the difference
                            my $diff = count::from_rice(sub {read_bits($BINARY2,1)}, $driving_col_rice_bits);
                            $val = count::num2str(count::str2num($previous_row[$c])+$diff,$col_to_max_length[$driving_column]);
                        }else{
                            my $length = $literal_lengths[$c];
                            $length = oct("0b$length");


                            if(defined $col_to_literal_bits[$c]){
                                my $bits_per_char=$col_to_literal_bits[$c];
                                $val='';
                                for (my $i=0;$i<$length;$i++){
                                    my $bits = read_bits($BINARY2,$bits_per_char);
                                    $val .= $col_to_alpha_idx_to_char[$c]->[oct("0b$bits")];
                                }
                            }else{
                                $val = read_bits($BINARY2,$length*8);
                                $val = count::bitstring_to_bytes($val);
                            }
                        }

                        push @{$col_to_stored_vals[$c]}, $val;

                        if($do_store_bits[$c]==0){
                            #warn "DELETING\n";
                            my $delete_idx = $#{$col_to_stored_vals[$c]};
                            splice(@{$col_to_stored_vals[$c]}, $delete_idx, 1);
                        }
                    }else{
                        die "wat";
                    }

                }
            }
            $vals[$c] = $val;

            #warn "col $c undef, idx $idx, $col_to_bits[$c] bit slice, max index $#{$col_to_sorted_keys[$c]}\n" unless defined $val;

        }

        seek_till_byte_boundary($BINARY2);
        seek_till_byte_boundary($BINARY);

        #warn Dumper \%bitstring_buffers;

        #warn Dumper \@vals;
        for my $ceez(@predictor_cols){

            if($predictor_column_used{$ceez}){
                #warn Dumper \@col_to_value_to_last_seen_friends;
                #warn "colums $ceez is a predictor col, it should have a value";
                my @ceez_refers = split /-/, substr($ceez,0,-4);
                #warn encode_json [map {$vals[$_]} @ceez_refers];
                my $value = freeze([map {$vals[$_]} @ceez_refers]);
                #warn $value;
                my @friends;
                if(exists $col_to_value_to_most_popular_friends{$ceez}->{$value}){
                    @friends = @{thaw $col_to_value_to_most_popular_friends{$ceez}->{$value}};
                }elsif(exists $col_to_most_popular_friends{$ceez}){
                    @friends = @{thaw $col_to_most_popular_friends{$ceez}};
                }else{
                    die "You're just unpredictable.";
                }
                my $ci=0;
                for my $cc(@{$col_to_predicted_cols{$ceez}}){

                    $vals[$cc] = $friends[$ci];
                    $ci++;
                }
            }

        }
        @previous_row = @vals;
        for (my $c=0;$c<$n_cols;$c++){
            die "col $c undef\n" unless defined $vals[$c];
            #print Dumper \@vals;
            #print Dumper \%predictor_column_used;
        }

        for my $ceez(@predictor_cols){
            my @ceez_refers = split /-/, substr($ceez,0,-4);

            my $value = freeze([map {$vals[$_]} @ceez_refers]);
            my @friends_i = @{$col_to_predicted_cols{$ceez}};
            my @friends;
            for my $f(@friends_i){
                push @friends, $vals[$f];
            }
            my $friends_str = freeze(\@friends);
            $col_to_value_to_friends_str_to_count{$ceez}->{$value}{$friends_str}++;
            my $new_count = $col_to_value_to_friends_str_to_count{$ceez}->{$value}{$friends_str};
            if((not defined $col_to_value_to_most_popular_friends{$ceez}->{$value}) or ($new_count >= $col_to_value_to_friends_str_to_count{$ceez}->{$value}->{$col_to_value_to_most_popular_friends{$ceez}->{$value}})){
                $col_to_value_to_most_popular_friends{$ceez}->{$value}=$friends_str;
            }
            $col_to_friends_str_to_count{$ceez}->{$friends_str}++;
            $new_count = $col_to_friends_str_to_count{$ceez}->{$friends_str};
            if((not defined $col_to_most_popular_friends{$ceez}) or ($new_count >= $col_to_friends_str_to_count{$ceez}->{$col_to_most_popular_friends{$ceez}})){
                $col_to_most_popular_friends{$ceez}=$friends_str;
            }
        }

        for (my $c=0;$c<$n_cols;$c++){
            if(defined $column_encodings[$c]){
                my $val = $vals[$c];
                if($column_encodings[$c] eq 'uuid'){
                    $val = count::short_uuid_unbinarize $val;
                }elsif($column_encodings[$c] eq 'ip'){
                    $val = count::ip_unbinarize $val;
                }elsif($column_encodings[$c] eq 'datetime'){
                    $val = count::datetime_from_integer $val;
                }
                $vals[$c]=$val;
            }
        }

        while($dupes>0){
            my $row_string = (join "\t", @vals);
            print ($row_string."\n");
            if($check_sum){
                $rows_sum += count::str2num(substr(md5($row_string),0,3));#first 3 bytes of md5 sum
            }
            $dupes--;
            $r++;
        }

    }

    if($r != $correct_n_rows){
        warn "Decoded the wrong number of rows, is $r, should be $correct_n_rows\n";
    }
    if($check_sum){
        if($rows_sum == $correct_rows_sum){
            warn "Row checksum good\n";
        }else{
            die "Row checksum BAD: is $rows_sum - should be $correct_rows_sum\n";
        }
    }
    #warn Dumper \%col_to_value_to_most_popular_friends;
}

else{
    #operating mode = C

    my $binary_fileno = fileno $BINARY;
    my $binary2_fileno = fileno $BINARY2;

    my $max_passed_fd = max($binary_fileno, $binary2_fileno);

    my $csrc = "#line ".(__LINE__+2)."\n";
    $csrc.=<<'ENDC';

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>

#include <unordered_map>

#define INLINE __attribute__((always_inline)) static
#define PURE __attribute__((pure))
#define MAYBE __attribute__((unused))
#include "count.h"




ENDC

    $csrc .= "#define MAX_FDS ".($max_passed_fd+1)."\n";

$csrc.=<<'ENDC';
unsigned char fd_to_ibuff[MAX_FDS][64*1024] = {  };
int  fd_to_ibuff_len[MAX_FDS]               = {  };
int  fd_to_ibuff_pos[MAX_FDS]               = {  };
char fd_to_ibuff_bit_pos[MAX_FDS]           = {  };
unsigned char fd_to_ibuff_bit_mask[MAX_FDS];

INLINE int read_some_bytes(int fd){
    //Only call when ibuff is empty
    int amt = read(fd,fd_to_ibuff[fd],64*1024-1);
    fd_to_ibuff_len[fd]=amt;
    fd_to_ibuff_pos[fd]=0;
    fd_to_ibuff_bit_pos[fd]=0;
    fd_to_ibuff_bit_mask[fd]=128;

    return amt;
}


INLINE unsigned char read_bit(int fd){
    if(fd_to_ibuff_bit_pos[fd]==8){
        fd_to_ibuff_bit_pos[fd]=0;
        fd_to_ibuff_bit_mask[fd]=128;
        fd_to_ibuff_pos[fd]++;
    }
    if(fd_to_ibuff_pos[fd] > fd_to_ibuff_len[fd]-1){
        if(read_some_bytes(fd)==0){
            //OUT OF DATA
            die("Prematurely out of data.\n");
        }
    }
    unsigned char bit = (fd_to_ibuff[fd][fd_to_ibuff_pos[fd]] & fd_to_ibuff_bit_mask[fd]) ? 1 : 0;

    fd_to_ibuff_bit_pos[fd]++;
    fd_to_ibuff_bit_mask[fd] >>= 1;
    return bit;

}

INLINE uint32_t read_bits_as_number(int fd, int n_bits){
    uint32_t val = 0;

    for (int i=0;i < n_bits; i++){
        val <<= 1;
        val |= read_bit(fd);
    }
    return val;
}

INLINE int stream_finished(int fd){
    if(fd_to_ibuff_bit_pos[fd]==8){
        fd_to_ibuff_bit_pos[fd]=0;
        fd_to_ibuff_bit_mask[fd]=128;
        fd_to_ibuff_pos[fd]++;
    }
    if(fd_to_ibuff_pos[fd] > fd_to_ibuff_len[fd]-1){
        if(read_some_bytes(fd)==0){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}

INLINE void seek_till_byte_boundary(int fd){
    if(fd_to_ibuff_bit_pos[fd]>0){
        fd_to_ibuff_bit_pos[fd]=0;
        fd_to_ibuff_bit_mask[fd]=128;
        fd_to_ibuff_pos[fd]++;
    }
}

int main(int argc, char ** argv){

ENDC
    $csrc.=<<ENDC;
    const int BINARY = $binary_fileno;
    const int BINARY2 = $binary2_fileno;
    const __uint128_t one = 1;
    //__uint128_t test=one<<5;
    string_id col_to_stored_vals[$max_stored_vals]; //FLAT ARRAY for all cols
    int col_to_n_stored_vals[$n_cols]={0};

    //my %col_to_value_to_friends_str_to_count;
    //my %col_to_value_to_most_popular_friends;
    //my %col_to_friends_str_to_count;
    //my %col_to_most_popular_friends;
    uint64_t col_to_ref_count[$n_cols];
    uint64_t col_to_ref_sum[$n_cols];
ENDC
    $csrc.=<<'ENDC';
    int r=0;

    while(! stream_finished(BINARY)){

ENDC
    #$csrc.= "        const int n_cols = $n_cols;\n";
    $csrc.= "        const int driving_column = $driving_column;\n";
    $csrc.= "        const int n_predictors = $#predictor_cols+1;\n";
    #$csrc.= "        char col_was_predicted[$n_cols]={0};\n";
    #$csrc.= "        char predictor_column_used[$#predictor_cols+1]={0};\n";
    $csrc.= "        ".count::ctype_for_bitarray($n_cols)." col_was_predicted=0;\n";
    $csrc.= "        ".count::ctype_for_bitarray($#predictor_cols+1)." predictor_column_used=0;\n";
    $csrc.= "        for(int i=0;i<n_predictors;i++){\n";
    $csrc.= "            \n";
    $csrc.= "            int need_predictor_bit=1;\n";
    $csrc.= "            \n";
    $csrc.= "            switch(i){\n";
    for(my $i=0;$i<=$#predictor_cols;$i++){
        $csrc.= "                case $i: {if(0!=((~col_was_predicted) & (".(join "|", map {"(one<<$_)"} @{$col_to_predicted_cols{$predictor_cols[$i]}})."))){need_predictor_bit=0;} break;}\n";
    }
    $csrc.= "            }\n";
    $csrc.= "            if(need_predictor_bit){\n";
    $csrc.= "                if(read_bit(BINARY)){\n";
    $csrc.= "                    predictor_column_used|=one<<i;\n";
    $csrc.= "                    switch(i){\n";
    for(my $i=0;$i<=$#predictor_cols;$i++){
        $csrc.= "                        case $i: {col_was_predicted|=(".(join "|", map {"(one<<$_)"} @{$col_to_predicted_cols{$predictor_cols[$i]}}).");break;}\n";
    }
    $csrc.= "                    }\n";
    $csrc.= "                }\n";
    $csrc.= "            }\n";
    $csrc.= "            \n";
    $csrc.= "        }\n";
    $csrc.= "        string_id vals[$n_cols]           ={0};\n";
    $csrc.= "        string_id previous_row[$n_cols]   ={0};\n";
    $csrc.= "        ".count::ctype_for_bitarray($n_cols)." copy_bits=0;\n";
    $csrc.= "        ".count::ctype_for_bitarray($n_cols)." encoding_choice_bits=0;\n";
    $csrc.= "        ".count::ctype_for_bitarray($n_cols)." do_store_bits=0;\n";
    $csrc.= "        int literal_lengths[$n_cols];\n";
    $csrc.= "        \n";
    $csrc.= "        \n";

    $csrc.= "        for (int c=0;c<$n_cols;c++){\n";
    $csrc.=<<'ENDC';
            if(col_was_predicted & (one<<c)){
                continue;
            }

            unsigned char copy_bit = read_bit(BINARY);
            if(copy_bit){
                copy_bits|=(one<<c);
            }

            //$encoding_list .= "COPY  " if $copy_bit;

            if(copy_bit != 1){
                unsigned char encoding_choice_bit = read_bit(BINARY);

                if(encoding_choice_bit){
                    encoding_choice_bits|=(one<<c);
                    if(read_bit(BINARY)){
                        do_store_bits|=(one<<c);
                    }

                }

                /*
                if(encoding_choice_bits[c]){
                    $encoding_list .= "LIT-$do_store_bits[$c] ";
                }else{
                    $encoding_list .= "REF   ";
                }
                */
            }
        }

        //warn "ROW $r: $encoding_list\n";

        seek_till_byte_boundary(BINARY);

ENDC


    $csrc.="        for (int c=0;c<$n_cols;c++){\n";
    $csrc.=<<'ENDC';
            if(col_was_predicted & (one<<c)){
                continue;
            }

            if(encoding_choice_bits & (one<<c)){
                if(c == driving_column && r!=0){
                //only encode the difference
                }else{
                    int max_length=0;
                    switch(c){
ENDC
    $csrc.=join "", map {"                        case $_: max_length = ".count::log2_int($col_to_max_length[$_]).";break;\n"} (0..($n_cols-1));
    $csrc.=<<'ENDC';
                    }
                    int length_length = max_length;
                    literal_lengths[c] = read_bits_as_number(BINARY,length_length);
                }
            }
        }

        int dupes=1;
        while(read_bit(BINARY)==1){
            dupes++;
        }


        seek_till_byte_boundary(BINARY);

ENDC



    $csrc.="        for (int c=0;c<$n_cols;c++){\n";
    $csrc.=<<'ENDC';
            if(col_was_predicted & (one<<c)){
                continue;
            }

            string_id val;

            if(copy_bits & (one<<c)){
                val = previous_row[c];
            }else{
                if((encoding_choice_bits & (one<<c))==0){

                }else{

                }
            }

        }
ENDC
    $csrc.=<<'ENDC';
        while(dupes>0){
            r++;
            dupes--;
        }
    }

    return 0;
}

ENDC


    my $filename = 'temp.c';
    my $execname = 'temp.exe';
    open my $cout, '>', $filename or die "cant open temp c file: $!";
    print $cout $csrc or die "cant print csrc: $!";
    close $cout;
    system('g++','-Wall','-std=c99','-s','-O3','-fwhole-program','-Winline','-ftree-vectorizer-verbose=2','-ffast-math','-msse2',$filename,'-o',$execname);#'-Wl,-emain', '-nostdlib', '-lc'

    die "compilation error" if $?;



    system(cwd().'/'.$execname);

}


