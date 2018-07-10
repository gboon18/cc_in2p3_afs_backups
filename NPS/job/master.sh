#$ -cwd
#$ -V
#$ -N Master
#$ -S /bin/sh
#$ -o MG.out
#$ -e MG.err
#$ -m a -M jknim19@gmail.com
#$ -m b -M jknim19@gmail.com
#$ -m e -M jknim19@gmail.com
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/default
qsub job.sh
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/all_absorb
qsub job.sh 
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/side_absorb
qsub job.sh 
cd /afs/in2p3.fr/home/h/hosanko/public/playground/geant4.10.03.p01_wMT/NPS/job/front_absorb
qsub job.sh 
