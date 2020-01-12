import cognitive_face as CF
import detectPerson
import random

def vertifyTwo(img_url1,img_url2):
    r1 = CF.face.detect(img_url1)
    r2= CF.face.detect(img_url2)
    print(r1)
    print(r2)
    r=CF.face.verify(r1[0]['faceId'],r2[0]['faceId'])
    print(r)
    return r['isIdentical']

def verifyTwoFaceId(faceId1,faceId2):
    r=CF.face.verify(faceId1,faceId2)
  #  CF.face.verify(faceId1,None,group_id,person_id)
    return r['isIdentical']

def getImgFaceId(imageNum):
    print(str(int(imageNum/ 2)) + ".jpg")
    #CF.face.detect("2.jpg")
    m=CF.face.detect(str(int(imageNum/ 2)) + ".jpg")
    if m:
        return m[0]['faceId']
    else:
        return ""


def randomTwoImg(imageNum):
    firstNum = random.randint(0, imageNum)
    img_url1 = str(firstNum) + ".jpg"

    secondNum = random.randint(0, imageNum)
    if (secondNum == firstNum):
        secondNum = firstNum + 1
    img_url2 = str(secondNum) + ".jpg"
    return img_url1,img_url2


class CogFace:
    def __init__(self):
        KEY = 'ced0b00ff29c4742958c93e63deb1964'  # Replace with a valid Subscription Key here.
        CF.Key.set(KEY)
        self.group_id = "1234567890"
        self.group_name = "students"
        #self.group_id=\
        try:
            CF.person_group.create(self.group_id,self.group_name)
        except CF.CognitiveFaceException:
            pass
        print(self.group_id)

    def addFaces(self,imageNum, username, userdata):
        try:
            personId = CF.person.create(self.group_id, username, userdata)
        except CF.CognitiveFaceException:
            print("This person has existed.")
            return

        flag = 1
        counterUseless=0
        while flag < imageNum:
            imgName=str(flag) + ".jpg"
            try:
                res=CF.person.add_face(imgName, self.group_id, personId['personId'])
            except CF.CognitiveFaceException:
                   counterUseless+=1
            print("add Face: ")
     #       print(res)
            flag += 1
        if imageNum-counterUseless<2:
            detectPerson.getOnePersonImg(imageNum)
            self.addFaces(imageNum,username,userdata)



    def getGroupPersons(self):
        try:
            allPersons=CF.person.lists(self.group_id)
        except CF.util.CognitiveFaceException:
            return None
        return allPersons

    def deleteAllPersons(self):
        allPers=self.getGroupPersons()
        if allPers:
            for per in allPers:
                CF.person.delete(self.group_id, per['personId'])



    def deleteGroupPersons(self,idName):
        CF.person_group.delete(idName)

    def matchFaceIdwithPerson(self,faceId,personId):
        try:
            res=CF.face.verify(faceId,None,self.group_id,personId)
        except CF.util.CognitiveFaceException:
            return False
        print(res)
        return res['confidence']>0.8
