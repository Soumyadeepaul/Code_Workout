##https://leetcode.com/problems/binary-watch/description/

class Solution:
    global m
    m=[32,16,8,4,2,1]
    def helperM(self,minutes, val, idx, store):
        ## take not take
        if minutes==0:
            if val>59:
                return
            store.add(val)
            return
        if idx==6:
            return
        self.helperM(minutes,val,idx+1,store)
        for i in range(idx,6):
            self.helperM(minutes-1,val+m[i],i+1,store)
        
    def helperH(self,hour,minutes,result):
        if hour==0 :
            store=set()
            self.helperM(minutes,0,0,store)
            for i in store:
                x=str(i)
                if len(x)==1 and x>='0' and x<='9':
                    x="0"+x
                result.append("0:"+x)
        elif hour==1:
            store=set()
            self.helperM(minutes,0,0,store)
            for i in store:
                x=str(i)
                if len(x)==1 and x>='0' and x<='9': 
                    x="0"+x
                result.append("1:"+x)
                result.append("2:"+x)
                result.append("4:"+x)
                result.append("8:"+x)

        elif hour==2 :
            store=set()
            self.helperM(minutes,0,0,store)
            for i in store:
                x=str(i)
                if len(x)==1 and x>='0' and x<='9':
                    x="0"+x
                result.append("3:"+x)
                result.append("5:"+x)
                result.append("9:"+x)
                result.append("6:"+x)
                result.append("10:"+x)




        elif hour==3 :
            store=set()
            self.helperM(minutes,0,0,store)
            for i in store:
                x=str(i)
                if len(x)==1 and x>='0' and x<='9':
                    x="0"+x
                result.append("7:"+x)
                result.append("11:"+x)

    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        result=[]
        for i in range(0,turnedOn+1):
            hour=i
            minutes=turnedOn-i
            self.helperH(hour,minutes,result)
        result=sorted(result)
        return result
