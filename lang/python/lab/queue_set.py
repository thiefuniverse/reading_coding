import queue

class QueueDict:
    # store a absolute size dicts and just keep last state
    def __init__(self,size):
        # check size
        assert size > 0
        self.maxSize = size
        self.currentSize = 0 
        self.seperateDicts = queue.Queue(size) 
        self.realDict = {}

    def pushDict(self,di):
        # not full, add one to seqerateDicts and realDict
        if self.seperateDicts.full():
            oldDict = self.seperateDicts.get()
            for k in oldDict:
                if k in self.realDict and oldDict[k] == self.realDict[k]:
                    self.realDict.pop(k)
            self.seperateDicts.put(di)
            self.realDict.update(di)
        else:
            self.seperateDicts.put(di)
            self.realDict.update(di)

    def get(self, key):
        if key in self.realDict:
            return self.realDict[key]
        return ""

    def print(self):
        print(self.realDict)
    

        
if __name__ == '__main__':
    f = CacheDict(3)
    a = {'a1':1,'a2':6}
    b = {'b1':2,'b2':6}
    c = {'c1':3,'c2':6}
    d = {'d1':4,'d2':6}
    e = {'e1':5, 'e2':6}
    
    f.pushDict(a)
    f.print()
    f.pushDict(b)
    f.print()
    f.pushDict(c)
    f.print()
    f.pushDict(d)
    f.print()
    f.pushDict(e)
    f.print()


