#https://leetcode.com/problems/isomorphic-strings/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s)!=len(t):
            return False
        hashmap={}
        achived=set()
        for i in range(len(s)):
            if s[i] in hashmap:
                if hashmap[s[i]]==t[i]:
                    pass
                else:
                    return False
            else:
                if t[i] not in achived:
                    hashmap[s[i]]=t[i]
                    achived.add(t[i])
                else:
                    return False
        return True
