#!/bin/sh

#500 MeV    : 500 evt/run with 10  runs ~ 20hrs
#number of runs
for i in {1..10}
do
let "j= $i + 1"
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/magnet_opt/29012018/
qsub resolution_500MeV.sh 0 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/29012018/rootfiles/29012018_resolution_0_0mm_500MeV_"%04d$i".root "$i" "$j"
qsub resolution_500MeV.sh 0.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/29012018/rootfiles/29012018_resolution_0_5mm_500MeV_"%04d$i".root "$i" "$j"
qsub resolution_500MeV.sh 1 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/29012018/rootfiles/29012018_resolution_1_0mm_500MeV_"%04d$i".root "$i" "$j"
qsub resolution_500MeV.sh 1.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/29012018/rootfiles/29012018_resolution_1_5mm_500MeV_"%04d$i".root "$i" "$j"
qsub resolution_500MeV.sh 2 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/29012018/rootfiles/29012018_resolution_2_0mm_500MeV_"%04d$i".root "$i" "$j"
done

