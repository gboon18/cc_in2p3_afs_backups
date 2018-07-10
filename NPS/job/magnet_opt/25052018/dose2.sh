#!/bin/sh
#$ -l os=cl7
#$ -l sps=1
#$ -cwd
#$ -m a -M jknim19@gmail.com
#$ -e /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/25052018/outputs/
#$ -o /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/25052018/outputs/

cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/01052018_op_off_simple_save2/build/

if [ -z "$1" ] || [ -z "$2" ] || [ -z "$3" ] || [ -z "$4" ] || [ -z "$5" ] || [ -z "$6" ] || [ -z "$7" ]
  then
    echo "Wrong arg"
    exit
fi
gap=$1
nps_dist=$2
nps_angl=$3
field=$4
output=$5
seed1=$6
seed2=$7

echo "$seed1 $seed2"

#size of the gap between crystals, NPS distance, NPS angle, name of the outputfile & random seeds
printf "%s\n$gap%s\n$nps_dist%s\n$nps_angl%s\n$field%s\n$output%s\n$seed1%s\n$seed2" | ./AnaEx02 ../macros/mono_11GeV.mac
