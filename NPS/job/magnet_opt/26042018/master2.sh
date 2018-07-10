#!/bin/sh


#qsub dose.sh "gap" "NPS_distance" "NPS_angle" "field on or off (1 : on, 2 : off)" "outfile_dir_#ofRun" "seed1" "seed2"

#number of runs
for i in {1..100}
do
let "j= $i + 1"
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/magnet_opt/26042018/
qsub dose2.sh 1 4000 6.3 1 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/26042018/rootfiles/dose2_6_3_"$i".root "$i" "$j"
qsub dose2.sh 1 4000 16.6 1 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/26042018/rootfiles/dose2_16_6_"$i".root "$i" "$j"
qsub dose2.sh 1 4000 26.9 1 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/26042018/rootfiles/dose2_26_9_"$i".root "$i" "$j"
qsub dose2.sh 1 4000 37.2 1 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/26042018/rootfiles/dose2_37_2_"$i".root "$i" "$j"
done
