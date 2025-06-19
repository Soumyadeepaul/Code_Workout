#https://leetcode.com/problems/word-pattern/description/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        
        listed=s.split(" ")
        hashmap={}
        values=set()
        if len(listed)!=len(pattern):
            return False
        for i in range(len(listed)):
            if listed[i] in hashmap:
                if hashmap[listed[i]]==pattern[i]:
                    pass
                else:
                    return False
            else:
                if pattern[i] in values:
                    return False
                    
                hashmap[listed[i]]=pattern[i]
                values.add(pattern[i])
        return True
