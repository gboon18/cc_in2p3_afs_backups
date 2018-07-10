#!/bin/sh
#$ -l os=cl7
#$ -l sps=1
#$ -cwd
#$ -m a -M jknim19@gmail.com

cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/18042018_field_off/build/

if [ -z "$1" ] || [ -z "$2" ] || [ -z "$3" ] || [ -z "$4" ] || [ -z "$5" ] || [ -z "$6" ]
  then
    echo "Wrong arg"
    exit
fi
gap=$1
nps_dist=$2
nps_angl=$3
output=$4
seed1=$5
seed2=$6

echo "$seed1 $seed2"

#size of the gap between crystals, NPS distance, NPS angle, name of the outputfile & random seeds
printf "%s\n$gap%s\n$nps_dist%s\n$nps_angl%s\n$output\n$seed1\n$seed2" | ./AnaEx02 ../macros/test.mac
