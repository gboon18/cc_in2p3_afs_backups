#!/bin/sh

for i in 1 10 100 500
do
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/magnet_no_opt/
qsub resolution_"$i"MeV.sh 0 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/18012018/rootfiles/no_opt/18012018_resolution_00mm_"$i"MeV.root
qsub resolution_"$i"MeV.sh 0.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/18012018/rootfiles/no_opt/18012018_resolution_05mm_"$i"MeV.root
qsub resolution_"$i"MeV.sh 1 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/18012018/rootfiles/no_opt/18012018_resolution_10mm_"$i"MeV.root
qsub resolution_"$i"MeV.sh 1.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/18012018/rootfiles/no_opt/18012018_resolution_15mm_"$i"MeV.root
qsub resolution_"$i"MeV.sh 2 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/18012018/rootfiles/no_opt/18012018_resolution_20mm_"$i"MeV.root
done

for j in 1
do
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/magnet_no_opt/
qsub resolution_"$j"GeV.sh 0 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/18012018/rootfiles/no_opt/18012018_resolution_00mm_"$j"GeV.root
qsub resolution_"$j"GeV.sh 0.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/18012018/rootfiles/no_opt/18012018_resolution_05mm_"$j"GeV.root
qsub resolution_"$j"GeV.sh 1 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/18012018/rootfiles/no_opt/18012018_resolution_10mm_"$j"GeV.root
qsub resolution_"$j"GeV.sh 1.5 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/18012018/rootfiles/no_opt/18012018_resolution_15mm_"$j"GeV.root
qsub resolution_"$j"GeV.sh 2 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/18012018/rootfiles/no_opt/18012018_resolution_20mm_"$j"GeV.root
done

#qsub resolution_test.sh 2 /sps/clas/hosanko/NPS/geant4.10.03.p01_wMT/magnetic/18012018/rootfiles/no_opt/18012018_resolution_test_1GeV.root
