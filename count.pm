package count;

use strict;

use Data::Dumper;

use Digest::SHA qw(sha256);

use Data::UUID;

use MIME::Base64;

our $ug    = new Data::UUID;


sub log2_int{
    my $x=shift;
    return 0 if $x < 1;
    return int(log($x)/log(2))+1;
}

sub binary_digits{
    my $num = shift;
    my $num_digits = shift;

    return '' if $num_digits == 0 and $num==0;
    my $bits;
    if($num_digits==1){
        $bits = $num;
    }else{
        $bits = sprintf("%0$num_digits"."b", $num);
    }


    warn "$num ->  $bits ; not $num_digits digits" if length($bits) != $num_digits;
    return $bits;
}

sub bitstring_to_bytes{
    my $bitstring=shift;
    $bitstring .= '0' x (8-(length($bitstring)%8)) if length($bitstring)%8>0;
    return pack("B*", $bitstring);
}

sub bytes_to_bitstring{
    my $bytes=shift;
    $bytes = unpack("B*",$bytes);
    return $bytes;
}

#print binary_digits(15,8);exit;

sub uuid_binarize{
    my $uuid = shift;
    return $ug->from_string($uuid);
}

sub uuid_unbinarize{
    my $uuid=shift;
    return $ug->to_string($uuid);
}

sub uuid_to_64bits{
    my $uuid = shift;

    $uuid  =  uuid_binarize($uuid);
    $uuid  =  substr(sha256($uuid),0,8);
    return $uuid;
}

sub shorten_uuid{
    my $uuid = shift;
    return encode_base64(substr(sha256($ug->from_string($uuid)),0,8),'');
}

sub short_uuid_binarize{
    my $short = shift;

    return decode_base64($short);
}
sub short_uuid_unbinarize{
    my $short = shift;

    return encode_base64($short,'');
}


sub ip_binarize{
    my $ip=shift;
    $ip =~ s/(\d+)\.?/chr($1)/ge;
    return $ip;
}

sub ip_unbinarize{
    my $ip=shift;
    $ip = join ".", unpack("CCCC",$ip);
    return $ip;
}

sub datetime_to_integer{
    my $datetime=shift;
    #2014-04-29 23:50:01
    my $diff=0;
    #diff may grow past 32 bit values
    if($datetime =~ /^(\d\d\d\d)-(\d\d)-(\d\d) (\d\d):(\d\d):(\d\d)$/){
        my ($y, $mo, $d, $h, $mi, $s) = ($1, $2, $3, $4, $5, $6);

        $y -= 2000;
        $y = 0 if $y < 0;

        $diff += $y;
        $diff *= 12;
        $diff += $mo;
        $diff *= 31;
        $diff += $d;
        $diff *= 24;
        $diff += $h;
        $diff *= 60;
        $diff += $mi;
        $diff *= 60;
        $diff += $s;
    }else{
        $diff = 0;
    }

    return $diff;
}

sub datetime_from_integer{
    my $diff= shift;

    my $s = $diff % 60;
    $diff -= $s;
    $diff /= 60;
    my $mi = $diff % 60;
    $diff -= $mi;
    $diff /= 60;
    my $h  = $diff % 24;
    $diff -= $h;
    $diff /= 24;
    my $d  = $diff % 31;
    $diff -= $d;
    $diff /= 31;
    my $mo = $diff % 12;
    $diff -= $mo;
    $diff /= 12;
    my $y  = $diff + 2000;

    return sprintf("%04d-%02d-%02d %02d:%02d:%02d", $y, $mo, $d, $h, $mi, $s);

}


1;