#https://leetcode.com/problems/valid-anagram/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        hashmap={}
        for i in s:
            if i not in hashmap:
                hashmap[i]=1
            else:
                hashmap[i]+=1
        for i in t:
            if i not in hashmap:
                return False
            hashmap[i]-=1
            if hashmap[i]<0:
                return False
        for i in hashmap:
            if hashmap[i]!=0:
                return False
        return True
