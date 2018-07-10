#!/bin/sh


#qsub dose.sh "gap" "NPS_distance" "NPS_angle" "field on or off (1 : on, 2 : off)" "outfile_dir_#ofRun" "seed1" "seed2"

#number of runs
for i in {1..100}
do
let "j= $i + 1"
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/magnet_opt/01052018/
qsub dose.sh 1 4000 6.3 1 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/01052018/rootfiles/dose_field_on_6_3_"$i".root "$i" "$j"
qsub dose.sh 1 4000 16.6 1 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/01052018/rootfiles/dose_field_on_16_6_"$i".root "$i" "$j"
qsub dose.sh 1 4000 26.9 1 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/01052018/rootfiles/dose_field_on_26_9_"$i".root "$i" "$j"
qsub dose.sh 1 4000 37.2 1 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/01052018/rootfiles/dose_field_on_37_2_"$i".root "$i" "$j"

qsub dose.sh 1 4000 6.3 0 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/01052018/rootfiles/dose_field_off_6_3_"$i".root "$i" "$j"
qsub dose.sh 1 4000 16.6 0 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/01052018/rootfiles/dose_field_off_16_6_"$i".root "$i" "$j"
qsub dose.sh 1 4000 26.9 0 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/01052018/rootfiles/dose_field_off_26_9_"$i".root "$i" "$j"
qsub dose.sh 1 4000 37.2 0 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/01052018/rootfiles/dose_field_off_37_2_"$i".root "$i" "$j"
done
