import numpy as np
import cv2

cv2.setNumThreads(1)

print "Using", cv2.getNumThreads(), "threads"



ret = True
num_frames = 0
#cap = cv2.VideoCapture('/home/xavim/test.mp4')
cap = cv2.VideoCapture('/home/xavim/Downloads/TextInMotion-VideoSample-1080p.mp4')

while(ret & cap.isOpened()):
    ret, frame = cap.read()

    print "Error is", ret

    if(ret == True):
#        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
#
#        cv2.imshow('frame',gray)
        cv2.imshow('frame',frame)
        num_frames += 1;
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break


cap.release()
cv2.destroyAllWindows()
print "Number of frames displayed", num_frames


