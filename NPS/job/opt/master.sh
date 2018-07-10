#!/bin/sh

for i in 1 100
do
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/opt/default/
qsub default_"$i"MeV.sh
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/opt/all_absorb/
qsub all_"$i"MeV.sh
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/opt/front_absorb/
qsub front_"$i"MeV.sh
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/opt/side_absorb/
qsub side_"$i"MeV.sh
done

for j in 1 5 10 15
do
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/opt/default/
qsub default_"$j"GeV.sh
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/opt/all_absorb/
qsub all_"$j"GeV.sh
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/opt/front_absorb/
qsub front_"$j"GeV.sh
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/opt/side_absorb/
qsub side_"$j"GeV.sh
done
