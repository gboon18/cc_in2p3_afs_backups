#!/bin/sh

#beam energy
for l in {1..3}
do
#number of runs
for i in {1..3}
do


cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/magnet_opt/27012018/
qsub resolution.sh 0 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27012018/rootfiles/27012018_resolution_00mm_"$l"GeV_"$i".root "$i" 


done
done
