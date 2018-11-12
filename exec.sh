#!/bin/bash

for i in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16; do

export OMP_NUM_THREADS=$i
bash image_yolov3.sh

done
