#!/usr/bin/perl -w

use strict;

use Data::Dumper;

my ($a, $b) = @ARGV;

open A, '<', $a or die "cant open A:$!";
open B, '<', $b or die "cant open B:$!";

my $a_lines;

while(<A>){
    $a_lines->{$_}++;
}
close A;
while(<B>){
    if(not exists $a_lines->{$_}){
        die "Line in B not in A: $_";
    }

    $a_lines->{$_}--;

    delete $a_lines->{$_} if $a_lines->{$_}==0;
}
close B;
if(keys %$a_lines){
    my $n = $#{keys %$a_lines} +1;

    warn "$n lines in A that are not in B";

    for my $line(keys %$a_lines){
        warn "$a_lines->{keys %$a_lines} times: $line";
    }
    die '';
}


warn "Perfect match\n";