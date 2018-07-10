#!/bin/sh


#qsub dose.sh "gap" "NPS_distance" "NPS_angle" "field on or off (1 : on, 2 : off)" "outfile_dir_#ofRun" "seed1" "seed2"

#number of runs
for i in {1..1}
do
let "j= $i + 1"
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/magnet_opt/01052018/
qsub test.sh 1 4000 37.2 1 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/01052018/rootfiles/dose_field_off_37_2_"$i".root "$i" "$j"
done
