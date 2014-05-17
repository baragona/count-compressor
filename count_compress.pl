#!/usr/bin/perl -w

use strict;

use Data::Dumper;

#use Digest::SHA qw(sha256);

#use Data::UUID;

#my $ug    = new Data::UUID;
use Storable qw(store_fd nstore_fd freeze thaw);

use JSON::XS;

use count;


#covariant columns. If you know one column, you have a good guess at another column.

#Not all fields need to be named.
my %field_names = qw(
    0   mid
    1   sid
    2   ev
    3   ip
    4   ctry
    5   datetime
    6   pbmid
    7   uuid
    8   cookied
    9   hostnum
    10  os
    11  browser
    12  device
    13  state
    14  dma
    15  inmarket_clk
    16  inmarket_act
    17  inmarket_rt
    18  gender
);

my %field_name_to_col = map { $field_names{$_} => $_} keys %field_names;

warn Dumper \%field_name_to_col;

#MID SID EV REF_IP CTRY TIME PBMID UUID COOKIED HOSTNUM OS BROWSER DEVICE? STATE DMA INMARKET_CLK INMARKET_ACT INMARKET_RT GENDER
#But to assign predictors, the field must be named

#A lower level predictor CANNOT predict the driving column of a higher level one.

my @predictors=(

    [qw(uuid)] => [qw(sid ip ev cookied ctry state dma browser device os inmarket_clk inmarket_act inmarket_rt gender)],
    [qw(ip)]   => [qw(ev cookied ctry state dma browser device os inmarket_clk inmarket_act inmarket_rt gender)],
    [qw(sid)]  => [qw(ctry browser)],
    [qw(sid)]  => [qw(gender)],
    [qw(inmarket_clk)]  => [qw(inmarket_act inmarket_rt)],
    #pbmid => [qw(mid)],
    [qw(cookied)] => [qw(os browser device)],
    #[qw(browser)] => [qw(device)],
    #device => [qw(os browser)],
    [qw(os)]   => [qw(browser)],
    [qw(dma)]  => [qw(state ctry)],
    [qw(state)] => [qw(ctry)],
    [qw(sid pbmid ctry)]  => [qw(mid)],
    #[qw(sid)]  => [qw(mid)],
);

my @predictor_cols;

my %col_to_predicted_cols;

my @col_is_used_as_a_predictor;

for (my $i=0; $i<= $#predictors/2; $i++){

    my $left = join '-', map {$field_name_to_col{$_}} @{$predictors[2*$i]};
    $left .=sprintf("_%03d",$i);
    map {$col_is_used_as_a_predictor[$field_name_to_col{$_}] = 1} @{$predictors[2*$i]};

    push @predictor_cols, $left;
    $col_to_predicted_cols{$left} = [sort {$a <=> $b} map {$field_name_to_col{$_}} @{$predictors[2*$i+1]}];
}

my @sort_order;
# for (my $c=0;$c<$n_cols;$c++){
#     if($col_is_used_as_a_predictor[$c]){
#         push @sort_order, $c;
#     }
# }

@sort_order = map {$field_name_to_col{$_}} qw(ip uuid sid datetime);


#warn Dumper \@col_is_used_as_a_predictor;exit;

my $i=0;

my @fields_to_vals;

my @fields_to_char_to_pop;

my @fields_to_val_to_last_seen;

my @records;

my $bytes_read=0;

open INPUT_SAVE, ">INPUT_SAVE";

my $n_cols=0;

my @column_encodings;

$column_encodings[3]='ip';
$column_encodings[7]='uuid';
$column_encodings[5]='datetime';

my @col_to_max_length;

while(<>){
    $i++;
    $bytes_read += length($_);
    #print INPUT_SAVE $_;
    chomp;
    my @fields = split /\t/;

    my $ip = $fields[3];
    $n_cols = $#fields+1 if $#fields+1 > $n_cols;


    my $uuid = $fields[7];
    warn "BAD UUID '$uuid' " unless lc $uuid eq  lc count::uuid_unbinarize(count::uuid_binarize($uuid));
    $uuid = count::shorten_uuid($uuid);
    $fields[7] = $uuid;
    #warn Dumper \@fields;

    print INPUT_SAVE ((join "\t", @fields)."\n");


    $fields[7] = count::short_uuid_binarize($fields[7]);
    warn "BAD IP '$ip'" unless $ip eq count::ip_unbinarize(count::ip_binarize $ip);
    $fields[3]=count::ip_binarize $ip;
    #warn length($ip);

    my $datetime = $fields[5];
    my $int =  count::datetime_to_integer $datetime;
    my $d = count::datetime_from_integer $int;
    $fields[5]=$int;
    warn "$datetime\t$d\t$int\n" unless $datetime eq $d;



    #print Dumper \@fields;
    for(my $c=0;$c<=$#fields;$c++){

        $fields_to_vals[$c]->{$fields[$c]}++;

        $col_to_max_length[$c] = 0 unless $col_to_max_length[$c];
        $col_to_max_length[$c] = length($fields[$c]) if length($fields[$c]) > $col_to_max_length[$c];
    }

    push @records, \@fields;



    last if $i==100000;

}

#warn Dumper \@col_to_max_length;




for (my $c=0;$c<$n_cols;$c++){
    push @sort_order, $c unless grep {$c == $_} @sort_order;
}
warn Dumper \@sort_order;

my $sort_function = join " or ", (map {"(\$a->[$_] cmp \$b->[$_])"} @sort_order);

#warn $sort_function;

eval "\@records = sort {$sort_function} \@records";
die "sort eval error: $@" if $@;

for (my $c=0;$c<$n_cols;$c++){

    for my $val (keys %{$fields_to_vals[$c]}){
        for my $char(split //, $val){
            $fields_to_char_to_pop[$c]->{$char}++;
        }
    }

}

for (my $r=0;$r<=$#records;$r++){
    my $record = $records[$r];
    for (my $c=0;$c<$n_cols;$c++){
        $fields_to_val_to_last_seen[$c]->{$record->[$c]}=$r unless ($r!=0 and $records[$r-1]->[$c] eq $record->[$c]);
    }
}

my @col_is_numeric;

my @col_to_sorted_keys;

my @col_to_val_to_key_idx;

my @col_to_bits;

my @col_to_alphabet;

for (my $c=0;$c<$n_cols;$c++){
    my $is_numeric=1;
    my @sorted_keys = sort {$fields_to_vals[$c]->{$b} cmp $fields_to_vals[$c]->{$a}} keys %{$fields_to_vals[$c]};
    $col_to_sorted_keys[$c]=\@sorted_keys;

    my $n_keys = $#sorted_keys+1;
    my $bits_for_col = count::log2_int($n_keys-1);
    $col_to_bits[$c]=$bits_for_col;
    my %val_to_key_idx;
    my $i=0;
    for my $val (@sorted_keys){
        $val_to_key_idx{$val}=$i;

        if($is_numeric and $val =~ /\D/){
            $is_numeric=0;
        }
        $i++;
    }
    #warn "col $c is numeric: $is_numeric\n";
    $col_is_numeric[$c]=$is_numeric;
    $col_to_val_to_key_idx[$c]=\%val_to_key_idx;

    my @used_chars = keys %{$fields_to_char_to_pop[$c]};

    if($#used_chars <= 128){
        @used_chars = sort {$fields_to_char_to_pop[$c]->{$b} <=> $fields_to_char_to_pop[$c]->{$a}} @used_chars;

        $col_to_alphabet[$c]=join '', @used_chars;

    }

}

open BINARY, ">BINARY";
open BINARY2, ">BINARY2";
open INDEX, ">INDEX";
{
    local $Data::Dumper::Indent=0;
    local $Data::Dumper::Terse=1;
    #local $Data::Dumper::Useqq=1;
    local $Data::Dumper::Pair=',';
    print INDEX Dumper {
        #col_to_sorted_keys => \@col_to_sorted_keys,
        n_cols => $n_cols,
        column_encodings => \@column_encodings,
        field_names => \%field_names,
        col_to_predicted_cols => \%col_to_predicted_cols,
        predictor_cols => \@predictor_cols,
        col_to_max_length => \@col_to_max_length,
        col_to_alphabet => \@col_to_alphabet,
        };
    #print INDEX encode_json \@col_to_sorted_keys;
    #store_fd \@col_to_sorted_keys, \*INDEX;

}


# my @encoding_files;
# my @lit_length_files;
# my @literal_files;
# my @reference_files;
# for (my $c=0;$c<$n_cols;$c++){
#     open my $c1, '>', "OFILES2/encoding_$c" or die "cant open: $@";
#     open my $c2, '>', "OFILES2/lit_length_$c" or die "cant open: $@";
#     open my $c3, '>', "OFILES2/literal_$c" or die "cant open: $@";
#     open my $c4, '>', "OFILES2/reference_$c" or die "cant open: $@";
#
#     $encoding_files[$c]=$c1;
#     $lit_length_files[$c]=$c2;
#     $literal_files[$c]=$c3;
#     $reference_files[$c]=$c4;
# }
#
# open my $predictor_file, '>', "OFILES2/predictors" or die "cant open: $@";

#record format
# which columns are being used to make predictions + what is is being used to predict? (both inner and outer lists skip entries that offer no new prediction potential). No circular references.
#BYTE BOUNDARY
# for each column that is not predicted,
#   an encoded value.

#possible ways to encode a value that can't be predicted
#length limited literal with column's alphabet and add to store
#length limited literal with column's alphabet and Don't add
#refer to previous value, nth stored
#refer to previous value, nth stored AND delete from stored list
#copy from above

#dont store very short values, or values that are only seen once.

#CURRENT CHOICES:
# 0 - Use stored value
# 1 - Use Literal value, add to store


#SECOND BIT CHOICES:
# 0 - Delete / Don't store
# 1 - Keep in store


my @col_to_currently_stored_val_list;
my @col_to_currently_stored_val_hash;

my %col_to_value_to_friends_str_to_count;
my %col_to_value_to_most_popular_friends;

my %col_to_friends_str_to_count;
my %col_to_most_popular_friends;

my $rows_with_deletes=0;
my $rows_with_copies=0;
my $rows_with_refs=0;
my $rows_with_lits=0;
my $rows_using_a_predictor=0;

for (my $r=0;$r<=$#records;$r++){

    my $record = $records[$r];
    my $row_encoding_has_a_delete=0;
    my $row_encoding_has_a_copy=0;
    my $row_encoding_has_a_ref=0;
    my $row_encoding_has_a_lit=0;
    my $row_encoding_uses_predictor=0;
    my $bitstring='';



    my $row_header_bits='';
    my $row_value_bits='';
    my $row_lit_length_bits='';

    my %predictor_col_used;
    my %col_was_predicted;

    my $predictor_bits='';

    my $encoding_list='';

    for my $ceez(@predictor_cols){

        #check if you need to store a predictor used bit. if everything it would have predicted is already predicted, there is no need.
        my $need_predictor_bit=0;
        my @predicted_cols = @{$col_to_predicted_cols{$ceez}};
        CC: for my $cc(@predicted_cols){
            if(not exists $col_was_predicted{$cc}){
                $need_predictor_bit=1;
                last CC;
            }
        }
        if($need_predictor_bit){
            my $predictor_used_bit;

            my @ceez_refers = split /-/, substr($ceez,0,-4);

            my $value = freeze([map {$record->[$_]} @ceez_refers]);

            my $friends_str;
            my $which;
            if(exists $col_to_value_to_most_popular_friends{$ceez}->{$value}){
                $friends_str = $col_to_value_to_most_popular_friends{$ceez}->{$value};
                $which="normal";
            }elsif(exists $col_to_most_popular_friends{$ceez}){
                $friends_str = $col_to_most_popular_friends{$ceez};
                $which = "default";
            }else{

            }

            if(defined $friends_str){
                my @friends = @{thaw $friends_str};
                my $matches=1;
                my $ci=0;
                PREDICTED_COL: for my $cc(@predicted_cols){
                    my $prediction = $friends[$ci];
                    my $actual = $record->[$cc];
                    if($actual ne $prediction){
                        $matches=0;
                        last PREDICTED_COL;
                    }
                    $ci++;
                }
                #predictor match
                if($matches){
                    #warn "predictor match. col $c predicts $#predicted_cols+1 cols...\n";
                    die "LOLWAT" if $r==0;
                    #warn "Ding" if $which eq 'default';
                    #warn " dong" if $which eq 'normal';
                    for my $cc(@predicted_cols){
                        $col_was_predicted{$cc}=1;
                    }
                    $predictor_used_bit='1';
                    $predictor_col_used{$ceez}=1;
                    $row_encoding_uses_predictor=1;
                }else{
                    #predictor non-match
                    #warn "predictor MISMATCH col $c\n";
                    $predictor_used_bit='0';
                }
            }else{
                warn "predictor IMPOSSIBRU\n";
                $predictor_used_bit='0';
            }
            $predictor_bits .= $predictor_used_bit;
        }
    }
    #warn "\n".length($predictor_bits)." predictor bits\n\n";
    #warn Dumper \%predictor_col_used;

    #print $predictor_file count::bitstring_to_bytes($predictor_bits);

    $row_header_bits .= $predictor_bits;

    for my $ceez(@predictor_cols){
        my @ceez_refers = split /-/, substr($ceez,0,-4);

        my $value = freeze([map {$record->[$_]} @ceez_refers]);

        my @friends;
        for my $f(@{$col_to_predicted_cols{$ceez}}){
            push @friends, $record->[$f];
        }
        my $friends_str = freeze(\@friends);
        $col_to_value_to_friends_str_to_count{$ceez}->{$value}->{$friends_str}++;
        my $new_count = $col_to_value_to_friends_str_to_count{$ceez}->{$value}->{$friends_str};
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

        my $val = $record->[$c];


        #warn "skipping col 5???" if $col_was_predicted{$c} and $c==5;
        next if $col_was_predicted{$c};
        #my $bits;

        my $copy_bit=0;
        if($r!=0 and $val eq $records[$r-1]->[$c]){
            $copy_bit=1;
            $row_encoding_has_a_copy=1;
        }
        if($copy_bit){
            $row_header_bits.=$copy_bit;
            $encoding_list .= "COPY  ";
            #print {$encoding_files[0]} count::bitstring_to_bytes($copy_bit);
        }else{

            my $encoding_choice_bit;
            my $value_bits;
            if(exists $col_to_currently_stored_val_hash[$c]->{$val}){
                $encoding_choice_bit=0;
                $encoding_list .= "REF";
                $row_encoding_has_a_ref=1;
                $value_bits = count::binary_digits($col_to_currently_stored_val_hash[$c]->{$val}, count::log2_int($#{$col_to_currently_stored_val_list[$c]}));
                #warn "col $c used stored val $col_to_currently_stored_val_hash[$c]->{$val} of $#{$col_to_currently_stored_val_list[$c]}\n";

                #print {$reference_files[0]} count::bitstring_to_bytes($value_bits);

            }else{
                $encoding_choice_bit=1;
                $encoding_list .= "LIT";
                $row_encoding_has_a_lit=1;
                my $xfrm_val=$val;
                if(defined $col_to_alphabet[$c]){
                    $xfrm_val =~ s/(.)/count::binary_digits(index($col_to_alphabet[$c],$1), count::log2_int(length($col_to_alphabet[$c])-1))/gse;
                    $value_bits=$xfrm_val;
                }else{
                    $value_bits = count::bytes_to_bitstring($xfrm_val);
                }


                $row_lit_length_bits .= count::binary_digits(length($val), count::log2_int($col_to_max_length[$c]));
                #print {$lit_length_files[$c]} count::bitstring_to_bytes(count::binary_digits(length($val), count::log2_int($col_to_max_length[$c])));
                #print {$literal_files[$c]} $val;

                push @{$col_to_currently_stored_val_list[$c]}, $val;
                $col_to_currently_stored_val_hash[$c]->{$val} = $#{$col_to_currently_stored_val_list[$c]};
            }
            my $do_store_bit='';
            if($encoding_choice_bit==1){
                $do_store_bit=0;
                if($fields_to_val_to_last_seen[$c]->{$val} > $r){
                    $do_store_bit=1;
                }
                $encoding_list.= "-$do_store_bit ";
                if($do_store_bit==0){
                    $row_encoding_has_a_delete=1;
                    #warn "DELETING\n";
                    my $delete_idx=$col_to_currently_stored_val_hash[$c]->{$val};
                    splice(@{$col_to_currently_stored_val_list[$c]}, $delete_idx, 1);
                    delete $col_to_currently_stored_val_hash[$c]->{$val};
                    for (my $i=$delete_idx;$i<=$#{$col_to_currently_stored_val_list[$c]};$i++){
                        $col_to_currently_stored_val_hash[$c]->{$col_to_currently_stored_val_list[$c]->[$i]} = $i;
                    }
                }else{
                    #warn "KEEPING\n";
                }
            }
            #$bits = $copy_bit.$encoding_choice_bit.$do_store_bit.$value_bits;
            #print {$encoding_files[0]} count::bitstring_to_bytes($copy_bit.$encoding_choice_bit.$do_store_bit);

            $row_header_bits.=$copy_bit.$encoding_choice_bit.$do_store_bit;
            $row_value_bits .=$value_bits;
        }

        #$bitstring .= $bits;



    }


    if($row_encoding_has_a_delete){
        $rows_with_deletes++;
    }
    if($row_encoding_has_a_copy){
        $rows_with_copies++;
    }
    if($row_encoding_has_a_ref){
        $rows_with_refs++;
    }
    if($row_encoding_has_a_lit){
        $rows_with_lits++;
    }
    if($row_encoding_uses_predictor){
        $rows_using_a_predictor++;
    }

    #warn "row header is".length($row_header_bits)." bits\n";
#     $bitstring = $row_header_bits.$row_value_bits;
#
#     my $n_bits = length($bitstring);
#
#     my $n_bytes = int($n_bits/8);
#     $n_bytes++ if $n_bits % 8;
#     my $bytes = count::bitstring_to_bytes($bitstring);
    #warn "ROW $r: $encoding_list\n";
    my $bytes = count::bitstring_to_bytes($row_header_bits).count::bitstring_to_bytes($row_lit_length_bits);

    #warn "$n_bits,$bitstring ".length($bytes)." $n_bytes\n" if length($bytes) != $n_bytes;
    #print "$bitstring\n";
    die "too effing long" if length($bytes) > 255;
    #print BINARY chr(length($bytes));
    print BINARY $bytes;
    print BINARY2 count::bitstring_to_bytes($row_value_bits);


}


#warn Dumper \%col_to_value_to_most_popular_friends;

close INPUT_SAVE;
close INDEX;
close BINARY;
close BINARY2;

my $input_size = (-s 'INPUT_SAVE');
my $index_size = (-s 'INDEX');
my $binary_size = (-s 'BINARY');
my $binary2_size = (-s 'BINARY2');

`bzip2 -kf INPUT_SAVE`;
`bzip2 -kf INDEX`;
`bzip2 -kf BINARY`;
`bzip2 -kf BINARY2`;

my $input_bz2_size = (-s 'INPUT_SAVE.bz2');
my $index_bz2_size = (-s 'INDEX.bz2');
my $binary_bz2_size = (-s 'BINARY.bz2');
my $binary2_bz2_size = (-s 'BINARY2.bz2');
print "INPUT SIZE:\t$input_size\n";
print "INPUT Bz2:\t$input_bz2_size\n";
print "INDEX Bz2:\t$index_bz2_size\n";
print "BINARY Bz2:\t$binary_bz2_size\n";
print "BINARY2 Bz2:\t$binary2_bz2_size\n";
printf "Index  compressibility:\t%f\n", ($index_size/$index_bz2_size);
printf "Binary compressibility:\t%f\n", ($binary_size/$binary_bz2_size);
printf "Binary2 compressibility:\t%f\n", ($binary2_size/$binary2_bz2_size);
printf "Total Bz2 Output Size:\t%d\n", $binary_bz2_size+$index_bz2_size+$binary2_bz2_size;
printf "Savings ratio: %f\n", $input_bz2_size/($binary_bz2_size+$index_bz2_size+$binary2_bz2_size);

print "$rows_with_deletes rows have deletes\n";
print "$rows_with_copies rows have copies\n";
print "$rows_with_refs rows have refs\n";
print "$rows_with_lits rows have lits\n";
print "$rows_using_a_predictor use at least one predictor\n";


$Data::Dumper::Useqq=1;
#print Dumper \@fields_to_vals;

#print Dumper \@col_to_val_to_key_idx;
