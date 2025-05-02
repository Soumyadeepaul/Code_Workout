#https://leetcode.com/problems/dota2-senate/description/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        queueR=[]
        queueD=[]
        for i in range(len(senate)): #store the position
            if senate[i]=='R':
                queueR.append(i)
            else:
                queueD.append(i)
        while len(queueR)>0 and len(queueD)>0 :
            r=queueR.pop(0)
            d=queueD.pop(0)
            if r>d: #smaller value will remove larger value
                queueD.append(d+len(senate)) #modified value gets append becoz in multiple loop, last element can remove first element too, there for 0 position is modified to 0+len
            else:
                queueR.append(r+len(senate))
        if len(queueR)==0:
            return 'Dire'
        if len(queueD)==0:
            return 'Radiant'
            
