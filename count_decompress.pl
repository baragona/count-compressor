#!/usr/bin/perl -w

use strict;

use Data::Dumper;

use JSON::XS;

use count;

use Storable qw(store_fd nstore_fd freeze thaw);

my ($index_file, $binary_file) = @ARGV;

open INDEX, "<",  $index_file or die "cant open:$!";
open BINARY, "<",  $binary_file or die "cant open:$!";
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

my @col_to_predicted_cols = @{$index->{col_to_predicted_cols}};
my @predictor_cols = @{$index->{predictor_cols}};


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

#warn Dumper \@col_to_alpha_idx_to_char; exit;

my @col_to_stored_vals;

my @previous_row;
my @col_to_value_to_friends_str_to_count;
my @col_to_value_to_most_popular_friends;

my $bitstring_buffer='';
my $total_bits_read=0;
sub read_bits{
    my $n_bits=shift;

    if($n_bits > length($bitstring_buffer)){
        my $n_bits_to_read = $n_bits - length($bitstring_buffer);
        my $n_bytes = int($n_bits_to_read/8);
        $n_bytes++ if $n_bits_to_read % 8;

        my $data_read;
        read(BINARY, $data_read, $n_bytes) == $n_bytes or die "Couldn't read enough data.";
        $bitstring_buffer .= count::bytes_to_bitstring($data_read);
    }

    my $bits_to_return = substr($bitstring_buffer, 0, $n_bits);
    $bitstring_buffer = substr($bitstring_buffer, $n_bits);
    $total_bits_read += length($bits_to_return);
    return $bits_to_return;
}

sub stream_finished{
    return 0 if length($bitstring_buffer);

    my $byte;
    my $n_read = read(BINARY, $byte, 1);

    if($n_read){
        $bitstring_buffer .= count::bytes_to_bitstring($byte);
        return 0;
    }else{
        return 1;
    }

}

sub seek_till_byte_boundary{
    read_bits(8-($total_bits_read %8)) if ($total_bits_read %8)>0;
}



my $r=-1;
while(not stream_finished){
    $r++;
    #my $next_bit=0;
    my %col_was_predicted;
    my @col_to_predicted_val;
    my %predictor_column_used;
    for my $c(@predictor_cols){

        #check if you needed to store a predictor used bit. if everything it would have predicted is already predicted, there is no need.
        my $need_predictor_bit=0;
        my @predicted_cols = @{$col_to_predicted_cols[$c]};
        CC: for my $cc(@predicted_cols){
            if(not $col_was_predicted{$cc}){
                $need_predictor_bit=1;
                last CC;
            }
        }
        if($need_predictor_bit){
            my $predictor_bit = read_bits(1);
            #warn "$predictor_bit\n";
            if($predictor_bit){
                #predicted
                $predictor_column_used{$c}=1;
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

        my $copy_bit = read_bits(1);
        $copy_bits[$c]=$copy_bit;

        $encoding_list .= "COPY  " if $copy_bit;;

        if($copy_bit != 1){
            $encoding_choice_bits[$c] = read_bits(1);
            if($encoding_choice_bits[$c]){
                $do_store_bits[$c]=read_bits(1);
            }

            if($encoding_choice_bits[$c]){
                $encoding_list .= "LIT-$do_store_bits[$c] ";
            }else{
                $encoding_list .= "REF   ";
            }
        }
    }

    #warn "ROW $r: $encoding_list\n";

    seek_till_byte_boundary();

    my @literal_lengths;

    for (my $c=0;$c<$n_cols;$c++){
        next if $col_was_predicted{$c};
        if($encoding_choice_bits[$c]){
            my $length_length = count::log2_int($col_to_max_length[$c]);
            $literal_lengths[$c] = read_bits($length_length);
        }
    }

    seek_till_byte_boundary();

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
                    my $stored_value_length = count::log2_int($#{$col_to_stored_vals[$c]});
                    my $stored_val_bits = read_bits($stored_value_length);
                    my $stored_val_idx = oct("0b$stored_val_bits");
                    $val = $col_to_stored_vals[$c]->[$stored_val_idx];
                }elsif($encoding_choice_bit==1){
                    my $length = $literal_lengths[$c];
                    $length = oct("0b$length");


                    if(defined $col_to_literal_bits[$c]){
                        my $bits_per_char=$col_to_literal_bits[$c];
                        $val='';
                        for (my $i=0;$i<$length;$i++){
                            my $bits = read_bits($bits_per_char);
                            $val .= $col_to_alpha_idx_to_char[$c]->[oct("0b$bits")];
                        }
                    }else{
                        $val = read_bits($length*8);
                        $val = count::bitstring_to_bytes($val);
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



                #my $bits = substr($bitstring, $next_bit, $col_to_bits[$c]);
                #$next_bit += $col_to_bits[$c];
                #my $idx = oct("0b$bits");
                #my $val = $col_to_sorted_keys[$c]->[$idx];

                warn "read funky datetime!" if($c==5 and $val =~ /\D/);

            }
        }
        $vals[$c] = $val;

        #warn "col $c undef, idx $idx, $col_to_bits[$c] bit slice, max index $#{$col_to_sorted_keys[$c]}\n" unless defined $val;

    }


    #warn Dumper \@vals;
    for (my $c=0;$c<$n_cols;$c++){
        if($predictor_column_used{$c} and defined $vals[$c]){
            #warn Dumper \@col_to_value_to_last_seen_friends;
            #warn "col $c is a predictor col, it should have a value";

            my @friends = @{thaw $col_to_value_to_most_popular_friends[$c]->{$vals[$c]}};

            my $ci=0;
            for my $cc(@{$col_to_predicted_cols[$c]}){

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

    for (my $c=0;$c<$n_cols;$c++){
        if($col_to_predicted_cols[$c]){
            my @friends_i = @{$col_to_predicted_cols[$c]};
            my @friends;
            for my $f(@friends_i){
                push @friends, $vals[$f];
            }
            my $friends_str = freeze(\@friends);
            $col_to_value_to_friends_str_to_count[$c]->{$vals[$c]}{$friends_str}++;
            my $new_count = $col_to_value_to_friends_str_to_count[$c]->{$vals[$c]}{$friends_str};
            if((not defined $col_to_value_to_most_popular_friends[$c]->{$vals[$c]}) or ($new_count >= $col_to_value_to_friends_str_to_count[$c]->{$vals[$c]}->{$col_to_value_to_most_popular_friends[$c]->{$vals[$c]}})){
                $col_to_value_to_most_popular_friends[$c]->{$vals[$c]}=$friends_str;
            }

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

    #warn $bitstring;
    print ((join "\t", @vals)."\n");
    seek_till_byte_boundary();
}

#warn Dumper \@col_to_value_to_most_popular_friends;


