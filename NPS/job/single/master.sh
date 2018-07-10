#! /usr/local/bin/bash -l
#$ -cwd
#$ -V
#$ -N Master
#$ -S /bin/sh
#$ -o MG.out
#$ -e MG.err
#$ -m a -M jknim19@gmail.com
#$ -m b -M jknim19@gmail.com
#$ -m e -M jknim19@gmail.com
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.02.b01/NPS/job/single/
qsub job.sh
