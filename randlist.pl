#!/usr/bin/perl -w

use strict;

use Data::Dumper;

use count;
use JSON::XS;


open UUID_SAVE, '>', "UUID_SAVE" or die $!;
open RESTORED, '>', "RESTORED" or die $!;

sub rand8bytes{

    return join '', map {chr(int(rand(255)))} (0..7);

}

sub str2num{
    #use bigint;
    my $sum=0;
    for my $c(split //, shift()){
        $sum <<= 8;
        $sum+=ord($c);
    }
    return $sum;
}

sub num2str{
    #use bigint;
    my $num=shift;
    my $bytes=shift;


    my $str='';
    while($num){
        $str = chr($num & 0xFF)."$str";
        $num >>= 8;
    }
    if(length($str)<$bytes){
        $str = (chr(0) x ($bytes-length($str))) . $str;
    }
    return $str;
}

sub to_rice{
    use integer;
    my $x=shift;
    my $k=shift;
    #my $m = 1 << $k;
	#my $q = $x / $m;
	my $q = $x >> $k;
	my $i;

    my $bits='';

	for ($i=0; $i<$q; $i++){ $bits .= '1'; }
	$bits .= '0';

	for ($i=$k-1; $i>=0; $i--) { $bits .=  ($x >> $i) & 1;}

	return $bits;
}


# int m = 1 << k, q = 0, x, i;
#
# while (get_bit()) q++;
# x = m * q;
#
# for (i=k-1; i>=0; i--) x = x | (get_bit() << i);
#
# if (done) break;

sub from_rice{
    my $get_bit_f = shift;
    my $k = shift;
    my $m = 1 << $k;
    my $q = 0;
    my $x;
    my $i;

    while ($get_bit_f->()) {$q++;}
    $x = $m * $q;

    for ($i=$k-1; $i>=0; $i--) {$x = $x | ($get_bit_f->() << $i);}

    return $x;
}

my $rice_bits = count::rice_bits(64,43325);
print "Going to use $rice_bits rice bits\n";





my @strs;

for (0..43325){
    push @strs, rand8bytes;

}

my @sstrs = sort {$a cmp $b} @strs;

map {print UUID_SAVE "$_"} @sstrs;

my @snums = map {str2num $_} @sstrs;

print "\n\n\n";

my $lowest = $snums[0];

my @diffs;
for (my $i=1;$i<=$#snums;$i++){
    $diffs[$i-1]=$snums[$i]-$snums[$i-1];
}
#map {print "$_\n"} @diffs;
print "\n\n\n";
my $min_diff;

my $diff_sum=0;

for my $diff(@diffs){
    $min_diff = $diff unless defined $min_diff and $min_diff <= $diff;
    $diff_sum+=$diff;
}

print "min diff $min_diff\n";

$diff_sum /= $#diffs+1;

print "avg diff = $diff_sum\n";

#print 1/$diff_sum;

my $bitstring='';
for my $diff(@diffs){
    $bitstring .= to_rice($diff,$rice_bits);
}

print "final length: ".length($bitstring);



my $next_bit=0;

my $get_bit = sub{
    die "no bits for you" if $next_bit >=length($bitstring);

    my $bit = substr($bitstring, $next_bit,1);
    $next_bit++;
    return $bit;
};

my @restored;
push @restored, $lowest;

while($next_bit < length($bitstring)){
    push @restored, $restored[$#restored] + from_rice($get_bit, $rice_bits);
}

map {print RESTORED num2str($_,8)} @restored;

#warn Dumper \@restored;
