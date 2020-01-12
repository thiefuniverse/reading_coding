import detectPerson
import cog

from flask import Flask
from flask import request

app=Flask(__name__)
imageNum=6

@app.route("/",methods=['GET'])
def home():
    return "<h1>Hack PKU</h1>"


@app.route("/signinPerson",methods=['POST'])
def signinPerson():
    global imageNum,co
    detectPerson.getOnePersonImg(imageNum)
    username=request.form['username']
    userdata=request.form['userdata']
    co.addFaces(imageNum,username,userdata)
    return "sign in info: "+username+"  "+userdata



@app.route("/getImageFaceId",methods=['GET'])
def getImage():
    global imageNum
    detectPerson.getOnePersonImg(imageNum)
    return cog.getImgFaceId(imageNum)


@app.route("/matchSomeone",methods=['POST'])
def matchSomeone():
    global co
    faceId=request.form['newfaceid']
    allPersons=co.getGroupPersons()
    if allPersons:
        for per in allPersons:
            m = co.matchFaceIdwithPerson(faceId, per['personId'])
            if m:
                return per['personId']

    return "no match"


@app.route("/directMatchSomeone",methods=['GET'])
def directMatchSomeone():
    global co,imageNum

    detectPerson.getOnePersonImg(imageNum)
    thisImageId=cog.getImgFaceId(imageNum)
    allPersons = co.getGroupPersons()
    if allPersons:
        for per in allPersons:
            m = co.matchFaceIdwithPerson(thisImageId, per['personId'])
            if m:
                return per['personId']

    return "no_match"


@app.route("/deleteGroupPerson",methods=['POST'])
def deleteGroupPerson():
    idName=request.form['personGroupId']
    co.deleteGroupPersons(idName)
    return "delete all persons"

co=cog.CogFace()
#cog.getImgFaceId(6)
#cog.init()
print(co.getGroupPersons())
#co.deleteAllPersons()
app.run()

#detectPerson.getOnePersonImg(6)
#app.run()