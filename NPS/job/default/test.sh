#!/bin/sh

### Merge stdout et stderr in a single file
#$ -j y

echo "\nHello World!\n"

echo 'my working directory is: '
pwd

echo 'on the host: ' 
hostname
