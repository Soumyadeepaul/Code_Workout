#https://leetcode.com/problems/uncommon-words-from-two-sentences/description/?envType=problem-list-v2&envId=counting


class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        store=dict()
        s1List=list(s1.split(" "))
        s2List=list(s2.split(" "))
        present=set()
        for i in s1List:
            if i in present:
                store[i]+=1
            else:
                store[i]=1
                present.add(i)
        for i in s2List:
            if i in present:
                store[i]+=1
            else:
                store[i]=1
                present.add(i)
        result=[]
        for i in store.keys():
            if store[i]==1:
                result.append(i)
        return result
