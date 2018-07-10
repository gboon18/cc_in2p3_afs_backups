#!/bin/sh


#qsub resolution_#GeV.sh "gap" "outfile_dir_#ofRun" "seed1" "seed2"

#500 MeV    : 500 evt/run with 80  runs ~ 20hrs
#number of runs
for i in {1..20}
do
let "j= $i + 1"
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/magnet_opt/08022018/
#qsub resolution_500MeV.sh 0 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_0_0mm_500MeV_"%04d$i".root "$i" "$j"
#qsub resolution_500MeV.sh 0.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_0_5mm_500MeV_"%04d$i".root "$i" "$j"
#qsub resolution_500MeV.sh 1 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_1_0mm_500MeV_"%04d$i".root "$i" "$j"
#qsub resolution_500MeV.sh 1.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_1_5mm_500MeV_"%04d$i".root "$i" "$j"
#qsub resolution_500MeV.sh 2 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_2_0mm_500MeV_"%04d$i".root "$i" "$j"
qsub resolution_500MeV.sh 20 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_20_0mm_500MeV_"%04d$i".root "$i" "$j"
done

#1 GeV    : 250 evt/run with 40  runs ~ 20hrs
#number of runs
for i in {1..40}
do
let "j= $i + 1"
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/magnet_opt/08022018/
#qsub resolution_1GeV.sh 0 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_0_0mm_1GeV_"%04d$i".root "$i" "$j"
#qsub resolution_1GeV.sh 0.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_0_5mm_1GeV_"%04d$i".root "$i" "$j"
#qsub resolution_1GeV.sh 1 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_1_0mm_1GeV_"%04d$i".root "$i" "$j"
#qsub resolution_1GeV.sh 1.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_1_5mm_1GeV_"%04d$i".root "$i" "$j"
#qsub resolution_1GeV.sh 2 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_2_0mm_1GeV_"%04d$i".root "$i" "$j"
qsub resolution_1GeV.sh 20 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_20_0mm_1GeV_"%04d$i".root "$i" "$j"
done

#3.25 GeV : 111 evt/run with 90  runs
for i in {1..90}
do
let "j= $i + 1"
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/magnet_opt/08022018/
#qsub resolution_3_25GeV.sh 0 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_0_0mm_3_25GeV_"%04d$i".root "$i" "$j"
#qsub resolution_3_25GeV.sh 0.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_0_5mm_3_25GeV_"%04d$i".root "$i" "$j"
#qsub resolution_3_25GeV.sh 1 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_1_0mm_3_25GeV_"%04d$i".root "$i" "$j"
#qsub resolution_3_25GeV.sh 1.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_1_5mm_3_25GeV_"%04d$i".root "$i" "$j"
#qsub resolution_3_25GeV.sh 2 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_2_0mm_3_25GeV_"%04d$i".root "$i" "$j"
qsub resolution_3_25GeV.sh 20 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_20_0mm_3_25GeV_"%04d$i".root "$i" "$j"
done

#5.5 GeV  : 45  evt/run with 200 runs
for i in {1..220}
do
let "j= $i + 1"
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/magnet_opt/08022018/
#qsub resolution_5_5GeV.sh 0 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_0_0mm_5_5GeV_"%04d$i".root "$i" "$j"
#qsub resolution_5_5GeV.sh 0.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_0_5mm_5_5GeV_"%04d$i".root "$i" "$j"
#qsub resolution_5_5GeV.sh 1 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_1_0mm_5_5GeV_"%04d$i".root "$i" "$j"
#qsub resolution_5_5GeV.sh 1.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_1_5mm_5_5GeV_"%04d$i".root "$i" "$j"
#qsub resolution_5_5GeV.sh 2 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_2_0mm_5_5GeV_"%04d$i".root "$i" "$j"
qsub resolution_5_5GeV.sh 20 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_20_0mm_5_5GeV_"%04d$i".root "$i" "$j"
done

#7.25 GeV : 32  evt/run with 310 runs
for i in {1..310}
do
let "j= $i + 1"
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/magnet_opt/08022018/
#qsub resolution_7_75GeV.sh 0 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_0_0mm_7_75GeV_"%04d$i".root "$i" "$j"
#qsub resolution_7_75GeV.sh 0.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_0_5mm_7_75GeV_"%04d$i".root "$i" "$j"
#qsub resolution_7_75GeV.sh 1 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_1_0mm_7_75GeV_"%04d$i".root "$i" "$j"
#qsub resolution_7_75GeV.sh 1.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_1_5mm_7_75GeV_"%04d$i".root "$i" "$j"
#qsub resolution_7_75GeV.sh 2 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_2_0mm_7_75GeV_"%04d$i".root "$i" "$j"
qsub resolution_7_75GeV.sh 20 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_20_0mm_7_75GeV_"%04d$i".root "$i" "$j"
done


#10 GeV   : 25  evt/run with 400 runs
for i in {1..400}
do
let "j= $i + 1"
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/magnet_opt/08022018/
#qsub resolution_10GeV.sh 0 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_0_0mm_10GeV_"%04d$i".root "$i" "$j"
#qsub resolution_10GeV.sh 0.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_0_5mm_10GeV_"%04d$i".root "$i" "$j"
#qsub resolution_10GeV.sh 1 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_1_0mm_10GeV_"%04d$i".root "$i" "$j"
#qsub resolution_10GeV.sh 1.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_1_5mm_10GeV_"%04d$i".root "$i" "$j"
#qsub resolution_10GeV.sh 2 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_2_0mm_10GeV_"%04d$i".root "$i" "$j"
qsub resolution_10GeV.sh 20 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/08022018/rootfiles/08022018_resolution_20_0mm_10GeV_"%04d$i".root "$i" "$j"
done
