#!/bin/sh


#qsub dose.sh "gap" "NPS_distance" "NPS_angle" "outfile_dir_#ofRun" "seed1" "seed2"

#number of runs
for i in {1..1}
do
let "j= $i + 1"
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/magnet_opt/19042018/
qsub dose.sh 1 4000 6.3 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/19042018/rootfiles/dose_6_3_"$i".root "$i" "$j"
qsub dose.sh 1 4000 16.6 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/19042018/rootfiles/dose_16_6_"$i".root "$i" "$j"
qsub dose.sh 1 4000 26.9 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/19042018/rootfiles/dose_26_9_"$i".root "$i" "$j"
qsub dose.sh 1 4000 37.2 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/19042018/rootfiles/dose_37_2_"$i".root "$i" "$j"
done
