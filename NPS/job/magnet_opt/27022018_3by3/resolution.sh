#!/bin/sh
#$ -l os=cl7
#$ -l sps=1
#$ -cwd
#$ -m a -M jknim19@gmail.com

cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/17022018_NPS_only/build/

if [ -z "$1" ] || [ -z "$2" ] || [ -z "$3" ] || [ -z "$4" ]
  then
    echo "Wrong arg"
    exit
fi
gap=$1
output=$2
seed1=$3
seed2=$4

echo "$seed1 $seed2"

#size of the gap between crystals & name of the outputfile
printf "%s\n$gap%s\n$output\n$seed1\n$seed2" | ./AnaEx02 ../macros/test.mac
#printf "%s\n$gap%s\n$output\n$seed1\n$seed2" | ./AnaEx02 test.mac
