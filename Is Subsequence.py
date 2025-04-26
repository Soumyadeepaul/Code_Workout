#https://leetcode.com/problems/is-subsequence/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if len(s)==0:
            return True
        if len(t)==0:
            return False
        i=0
        j=0
        while j<len(t):
            if s[i]==t[j]:
                i+=1
                if i==len(s):
                    return True
            j+=1
        return False
        
