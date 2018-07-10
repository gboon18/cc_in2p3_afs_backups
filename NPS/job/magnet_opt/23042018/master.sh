#!/bin/sh


#qsub dose.sh "gap" "NPS_distance" "NPS_angle" "outfile_dir_#ofRun" "seed1" "seed2"

#number of runs
#for i in {1..10}
#for i in {11..20}
for i in {3..3}
do
let "j= $i + 1"
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/magnet_opt/23042018/
qsub dose.sh 1 4000 6.3 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/23042018/rootfiles/dose_"$i".root "$i" "$j"
#qsub dose.sh 0 4000 6.3 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/19042018/rootfiles/test_"$i".root "$i" "$j"
#qsub resolution_500MeV.sh 0.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/19042018/rootfiles/19042018_resolution_0_5mm_500MeV_"%04d$i".root "$i" "$j"
#qsub resolution_500MeV.sh 1 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/19042018/rootfiles/19042018_resolution_1_0mm_500MeV_"%04d$i".root "$i" "$j"
#qsub resolution_500MeV.sh 1.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/19042018/rootfiles/19042018_resolution_1_5mm_500MeV_"%04d$i".root "$i" "$j"
#qsub resolution_500MeV.sh 2 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/19042018/rootfiles/19042018_resolution_2_0mm_500MeV_"%04d$i".root "$i" "$j"
#qsub resolution_500MeV.sh 20 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/19042018/rootfiles/19042018_resolution_20_0mm_500MeV_"%04d$i".root "$i" "$j"
done
