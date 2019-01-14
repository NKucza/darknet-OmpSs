#!/bin/bash
if [ x$1 == x ]; then
  threads=1
else
  threads=$1
fi
echo Using $threads threads
export NX_ARGS="--smp-workers $1 --force-tie-master"
./darknet detector demo ./cfg/coco.data ./cfg/yolov3.cfg ../Downloads/yolov3.weights  -thresh 0.25 ~/test.mp4 
