#! /usr/local/bin/bash -l
#$ -cwd
#$ -V
#$ -N AnaOpt
#$ -S /bin/sh
#$ -o optical_single.out
#$ -e optical_single.err
#$ -m abe -M jknim19@gmail.com
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.02.b01/NPS/single_build
./AnaEx02 mono_1GeV.mac
echo "Job is Completed"         