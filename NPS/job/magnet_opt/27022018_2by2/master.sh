#!/bin/sh


#01032018 job all submitted!

#qsub resolution_#GeV.sh "gap" "outfile_dir_#ofRun" "seed1" "seed2"


#500 MeV    : 500 evt/run with 10  runs ~ 20hrs
#number of runs
#for i in {1..10}
for i in {11..20}
do
let "j= $i + 1"
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/magnet_opt/27022018_2by2/
#qsub resolution_500MeV.sh 0 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27022018_2by2/rootfiles/27022018_2by2_resolution_0_0mm_500MeV_"%04d$i".root "$i" "$j"
#qsub resolution_500MeV.sh 0.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27022018_2by2/rootfiles/27022018_2by2_resolution_0_5mm_500MeV_"%04d$i".root "$i" "$j"
#qsub resolution_500MeV.sh 1 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27022018_2by2/rootfiles/27022018_2by2_resolution_1_0mm_500MeV_"%04d$i".root "$i" "$j"
#qsub resolution_500MeV.sh 1.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27022018_2by2/rootfiles/27022018_2by2_resolution_1_5mm_500MeV_"%04d$i".root "$i" "$j"
#qsub resolution_500MeV.sh 2 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27022018_2by2/rootfiles/27022018_2by2_resolution_2_0mm_500MeV_"%04d$i".root "$i" "$j"
done

#1 GeV    : 250 evt/run with 20  runs ~ 20hrs
#number of runs
#for i in {1..20}
for i in {21..40}
do
let "j= $i + 1"
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/magnet_opt/27022018_2by2/
#qsub resolution_1GeV.sh 0 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27022018_2by2/rootfiles/27022018_2by2_resolution_0_0mm_1GeV_"%04d$i".root "$i" "$j"
#qsub resolution_1GeV.sh 0.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27022018_2by2/rootfiles/27022018_2by2_resolution_0_5mm_1GeV_"%04d$i".root "$i" "$j"
#qsub resolution_1GeV.sh 1 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27022018_2by2/rootfiles/27022018_2by2_resolution_1_0mm_1GeV_"%04d$i".root "$i" "$j"
#qsub resolution_1GeV.sh 1.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27022018_2by2/rootfiles/27022018_2by2_resolution_1_5mm_1GeV_"%04d$i".root "$i" "$j"
#qsub resolution_1GeV.sh 2 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27022018_2by2/rootfiles/27022018_2by2_resolution_2_0mm_1GeV_"%04d$i".root "$i" "$j"
done

#01032018 job is submitted to 1GeV 2mm.
#3.25 GeV : 111 evt/run with 45  runs
#for i in {1..45}
for i in {46..90}
do
let "j= $i + 1"
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/magnet_opt/27022018_2by2/
#qsub resolution_3_25GeV.sh 0 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27022018_2by2/rootfiles/27022018_2by2_resolution_0_0mm_3_25GeV_"%04d$i".root "$i" "$j"
#qsub resolution_3_25GeV.sh 0.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27022018_2by2/rootfiles/27022018_2by2_resolution_0_5mm_3_25GeV_"%04d$i".root "$i" "$j"
#qsub resolution_3_25GeV.sh 1 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27022018_2by2/rootfiles/27022018_2by2_resolution_1_0mm_3_25GeV_"%04d$i".root "$i" "$j"
#qsub resolution_3_25GeV.sh 1.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27022018_2by2/rootfiles/27022018_2by2_resolution_1_5mm_3_25GeV_"%04d$i".root "$i" "$j"
#qsub resolution_3_25GeV.sh 2 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27022018_2by2/rootfiles/27022018_2by2_resolution_2_0mm_3_25GeV_"%04d$i".root "$i" "$j"
done

#5.5 GeV  : 45  evt/run with 111 runs
#for i in {1..111}
for i in {112..222}
do
let "j= $i + 1"
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/magnet_opt/27022018_2by2/
#qsub resolution_5_5GeV.sh 0 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27022018_2by2/rootfiles/27022018_2by2_resolution_0_0mm_5_5GeV_"%04d$i".root "$i" "$j"
#qsub resolution_5_5GeV.sh 0.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27022018_2by2/rootfiles/27022018_2by2_resolution_0_5mm_5_5GeV_"%04d$i".root "$i" "$j"
#qsub resolution_5_5GeV.sh 1 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27022018_2by2/rootfiles/27022018_2by2_resolution_1_0mm_5_5GeV_"%04d$i".root "$i" "$j"
#qsub resolution_5_5GeV.sh 1.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27022018_2by2/rootfiles/27022018_2by2_resolution_1_5mm_5_5GeV_"%04d$i".root "$i" "$j"
#qsub resolution_5_5GeV.sh 2 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27022018_2by2/rootfiles/27022018_2by2_resolution_2_0mm_5_5GeV_"%04d$i".root "$i" "$j"
done

#01032018 job is submitted to 7.75GeV 1mm.
#7.75 GeV : 32  evt/run with 156 runs
#for i in {1..156}
for i in {157..312}
do
let "j= $i + 1"
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/magnet_opt/27022018_2by2/
#qsub resolution_7_75GeV.sh 0 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27022018_2by2/rootfiles/27022018_2by2_resolution_0_0mm_7_75GeV_"%04d$i".root "$i" "$j"
#qsub resolution_7_75GeV.sh 0.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27022018_2by2/rootfiles/27022018_2by2_resolution_0_5mm_7_75GeV_"%04d$i".root "$i" "$j"
#qsub resolution_7_75GeV.sh 1 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27022018_2by2/rootfiles/27022018_2by2_resolution_1_0mm_7_75GeV_"%04d$i".root "$i" "$j"
#qsub resolution_7_75GeV.sh 1.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27022018_2by2/rootfiles/27022018_2by2_resolution_1_5mm_7_75GeV_"%04d$i".root "$i" "$j"
#qsub resolution_7_75GeV.sh 2 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27022018_2by2/rootfiles/27022018_2by2_resolution_2_0mm_7_75GeV_"%04d$i".root "$i" "$j"
done

#03012018 10GeV 1.5mm and 2mm were submitted by mistake.
#10 GeV   : 25  evt/run with 200 runs
#for i in {1..200}
for i in {201..400}
do
let "j= $i + 1"
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/magnet_opt/27022018_2by2/
#qsub resolution_10GeV.sh 0 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27022018_2by2/rootfiles/27022018_2by2_resolution_0_0mm_10GeV_"%04d$i".root "$i" "$j"
qsub resolution_10GeV.sh 0.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27022018_2by2/rootfiles/27022018_2by2_resolution_0_5mm_10GeV_"%04d$i".root "$i" "$j"
qsub resolution_10GeV.sh 1 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27022018_2by2/rootfiles/27022018_2by2_resolution_1_0mm_10GeV_"%04d$i".root "$i" "$j"

#03012018 10GeV 1.5mm and 2mm were submitted by mistake.
#qsub resolution_10GeV.sh 1.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27022018_2by2/rootfiles/27022018_2by2_resolution_1_5mm_10GeV_"%04d$i".root "$i" "$j"
#qsub resolution_10GeV.sh 2 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/27022018_2by2/rootfiles/27022018_2by2_resolution_2_0mm_10GeV_"%04d$i".root "$i" "$j"
done
