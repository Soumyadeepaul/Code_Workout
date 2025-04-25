#https://leetcode.com/problems/reverse-vowels-of-a-string/description/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def reverseVowels(self, s: str) -> str:
        stack=[]
        vowel=['A','E','I','O','U','a','e','i','o','u']
        idx=[]
        s=list(s)
        for i in range(len(s)):
            if s[i] in vowel:
                stack.append(s[i])
                idx.append(i)
        for i in idx:
            s[i]=stack.pop()
        return ''.join(s)
        
