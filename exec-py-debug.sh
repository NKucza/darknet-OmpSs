#!/bin/bash

echo OMP_NUM_THREADS $OMP_NUM_THREADS
echo NX_ARGS $NX_ARGS
LD_PRELOAD=/home/xavim/Downloads/ompss/install/lib/debug/libnanox-ompss.so:/home/xavim/Downloads/ompss/install/lib/debug/libnanox-c.so:/home/xavim/Downloads/ompss/install/lib/debug/libnanox-pe-smp.so python3 darknet.py
