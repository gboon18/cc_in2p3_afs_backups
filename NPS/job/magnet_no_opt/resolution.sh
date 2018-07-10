#!/bin/sh
#$ -l os=cl7
#$ -cwd
#$ -m a -M jknim19@gmail.com

cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/18012018_NPS_fieldmap_op/build/

if [ -z "$1" ] || [ -z "$2" ]
  then
    echo "Wrong arg"
    exit
fi
gap=$1
output=$2
#echo "Variable 1 = $gap"
#echo "Variable 2 = $output"

#size of the gap between crystals & name of the outputfile
# %s is to print string variable
printf "%s\n$gap%s\n$output" | ./AnaEx02 macros/test.mac
