#!/bin/sh


#qsub resolution_#GeV.sh "gap" "outfile_dir_#ofRun" "seed1" "seed2"

#500 MeV    : 500 evt/run with 10  runs ~ 20hrs
#number of runs
for i in {1..10}
do
let "j= $i + 1"
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/magnet_opt/16022018/
qsub resolution_500MeV.sh 0 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_0_0mm_500MeV_"%04d$i".root "$i" "$j"
qsub resolution_500MeV.sh 0.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_0_5mm_500MeV_"%04d$i".root "$i" "$j"
qsub resolution_500MeV.sh 1 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_1_0mm_500MeV_"%04d$i".root "$i" "$j"
qsub resolution_500MeV.sh 1.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_1_5mm_500MeV_"%04d$i".root "$i" "$j"
qsub resolution_500MeV.sh 2 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_2_0mm_500MeV_"%04d$i".root "$i" "$j"
#qsub resolution_500MeV.sh 20 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_20_0mm_500MeV_"%04d$i".root "$i" "$j"
done

#1 GeV    : 250 evt/run with 20  runs ~ 20hrs
#number of runs
for i in {1..20}
do
let "j= $i + 1"
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/magnet_opt/16022018/
qsub resolution_1GeV.sh 0 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_0_0mm_1GeV_"%04d$i".root "$i" "$j"
qsub resolution_1GeV.sh 0.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_0_5mm_1GeV_"%04d$i".root "$i" "$j"
qsub resolution_1GeV.sh 1 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_1_0mm_1GeV_"%04d$i".root "$i" "$j"
qsub resolution_1GeV.sh 1.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_1_5mm_1GeV_"%04d$i".root "$i" "$j"
qsub resolution_1GeV.sh 2 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_2_0mm_1GeV_"%04d$i".root "$i" "$j"
#qsub resolution_1GeV.sh 20 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_20_0mm_1GeV_"%04d$i".root "$i" "$j"
done

#3.25 GeV : 111 evt/run with 45  runs
for i in {1..45}
do
let "j= $i + 1"
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/magnet_opt/16022018/
qsub resolution_3_25GeV.sh 0 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_0_0mm_3_25GeV_"%04d$i".root "$i" "$j"
qsub resolution_3_25GeV.sh 0.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_0_5mm_3_25GeV_"%04d$i".root "$i" "$j"
qsub resolution_3_25GeV.sh 1 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_1_0mm_3_25GeV_"%04d$i".root "$i" "$j"
qsub resolution_3_25GeV.sh 1.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_1_5mm_3_25GeV_"%04d$i".root "$i" "$j"
qsub resolution_3_25GeV.sh 2 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_2_0mm_3_25GeV_"%04d$i".root "$i" "$j"
#qsub resolution_3_25GeV.sh 20 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_20_0mm_3_25GeV_"%04d$i".root "$i" "$j"
done

#5.5 GeV  : 45  evt/run with 111 runs
for i in {1..111}
do
let "j= $i + 1"
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/magnet_opt/16022018/
qsub resolution_5_5GeV.sh 0 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_0_0mm_5_5GeV_"%04d$i".root "$i" "$j"
qsub resolution_5_5GeV.sh 0.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_0_5mm_5_5GeV_"%04d$i".root "$i" "$j"
qsub resolution_5_5GeV.sh 1 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_1_0mm_5_5GeV_"%04d$i".root "$i" "$j"
qsub resolution_5_5GeV.sh 1.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_1_5mm_5_5GeV_"%04d$i".root "$i" "$j"
qsub resolution_5_5GeV.sh 2 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_2_0mm_5_5GeV_"%04d$i".root "$i" "$j"
#qsub resolution_5_5GeV.sh 20 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_20_0mm_5_5GeV_"%04d$i".root "$i" "$j"
done

#7.25 GeV : 32  evt/run with 156 runs
for i in {1..156}
do
let "j= $i + 1"
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/magnet_opt/16022018/
qsub resolution_7_75GeV.sh 0 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_0_0mm_7_75GeV_"%04d$i".root "$i" "$j"
qsub resolution_7_75GeV.sh 0.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_0_5mm_7_75GeV_"%04d$i".root "$i" "$j"
qsub resolution_7_75GeV.sh 1 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_1_0mm_7_75GeV_"%04d$i".root "$i" "$j"
qsub resolution_7_75GeV.sh 1.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_1_5mm_7_75GeV_"%04d$i".root "$i" "$j"
qsub resolution_7_75GeV.sh 2 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_2_0mm_7_75GeV_"%04d$i".root "$i" "$j"
#qsub resolution_7_75GeV.sh 20 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_20_0mm_7_75GeV_"%04d$i".root "$i" "$j"
done


#10 GeV   : 25  evt/run with 200 runs
for i in {1..200}
do
let "j= $i + 1"
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/magnet_opt/16022018/
qsub resolution_10GeV.sh 0 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_0_0mm_10GeV_"%04d$i".root "$i" "$j"
qsub resolution_10GeV.sh 0.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_0_5mm_10GeV_"%04d$i".root "$i" "$j"
qsub resolution_10GeV.sh 1 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_1_0mm_10GeV_"%04d$i".root "$i" "$j"
qsub resolution_10GeV.sh 1.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_1_5mm_10GeV_"%04d$i".root "$i" "$j"
qsub resolution_10GeV.sh 2 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_2_0mm_10GeV_"%04d$i".root "$i" "$j"
#qsub resolution_10GeV.sh 20 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/16022018/rootfiles/16022018_resolution_20_0mm_10GeV_"%04d$i".root "$i" "$j"
done
