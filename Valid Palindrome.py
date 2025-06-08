#https://leetcode.com/problems/valid-palindrome/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def isPalindrome(self, s: str) -> bool:
        
        i=0
        j=len(s)-1
        s=s.lower()
        while i<j and i<len(s) and j>-1:
            while i<len(s) and  ( not (ord(s[i])>=97 and ord(s[i])<97+26) and  not (ord(s[i])>=48 and ord(s[i])<=57)):
                i+=1
            while j>-1 and (not (ord(s[j])>=97 and ord(s[j])<97+26) and  not (ord(s[j])>=48 and ord(s[j])<=57)):
                j-=1
            
            if i<len(s) and j>-1 and s[i]==s[j]:
                i+=1
                j-=1
            else:
                if i>=len(s) and j<0:
                    return True
                return False
        return True
