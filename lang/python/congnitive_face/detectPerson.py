import cv2
import time

import cognitive_face as CF
#import numpy as np


def getOnePersonImg(bigNum):
    counter=0
    video_ob = cv2.VideoCapture(0)
    if video_ob == None:
        print("No video capture")
    if video_ob.open(0) == False:
        print("Open error")

    upBound=100
    step=20
    while counter < bigNum+upBound:

        ret, img = video_ob.read()
        #  print
        font=cv2.FONT_HERSHEY_SIMPLEX

        if counter==bigNum+upBound-1:
            cv2.putText(img, "Collecting Completed!", (10, 100), font, 1, (125, 0, 255), 2)
            cv2.imshow("show", img)
            cv2.waitKey(10)
            time.sleep(1)
            cv2.destroyAllWindows()
            break
        elif counter%3==1:
            cv2.putText(img,"Collecting Image.",(10,100),font,1,(255,255,255),2)
        elif counter%3==2:
            cv2.putText(img, "Collecting Image..", (10, 100), font, 1, (255, 255, 0), 2)
        else:
            cv2.putText(img, "Collecting Image...", (10, 100), font, 1, (255, 0, 255), 2)


        cv2.imshow("show", img)
        cv2.waitKey(10)

        if counter%step==0 and counter>=step:
            cv2.imwrite(str(int(counter/step)) + ".jpg", img)
            #time.sleep(0.4)
        counter += 1

    video_ob.release()


def chooseOneImg(bigNum):
    return str(int(bigNum/2))+".jpg"

''