#!/bin/sh
#$ -l os=cl7
#$ -l sps=1
#$ -cwd
#$ -m a -M jknim19@gmail.com

cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/27012018_NPS_fieldmap_op/build/

if [ -z "$1" ] || [ -z "$2" ] || [ -z "$3" ]
  then
    echo "Wrong arg"
    exit
fi
gap=$1
output=$2

#change the seeds(get from master.sh as variables) in macros



i=$3

let "j= $i + 1"




echo "$i $j $gap $output"
sed -i "s:/random/setSeeds 0 1:/random/setSeeds $i $j:" ../macros/test.mac 


#size of the gap between crystals & name of the outputfile
printf "%s\n$gap%s\n$output" | ./AnaEx02 ../macros/test.mac 

sed -i "s:/random/setSeeds $i $j:/random/setSeeds 0 1:" ../macros/test.mac 
echo "$i $j $gap $output"
