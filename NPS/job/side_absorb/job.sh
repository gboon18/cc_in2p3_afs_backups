#! /usr/local/bin/bash -l
#$ -cwd
#$ -V
#$ -N AnaOpt_1MeV
#$ -S /bin/sh
#$ -o optical_1MeV.out
#$ -e optical_1MeV.err
#$ -m abe -M jknim19@gmail.com
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/14112017_opt/build_side/
./AnaEx02 mono_1MeV.mac
echo "Job is Completed"         
