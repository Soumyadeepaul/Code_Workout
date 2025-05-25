#https://leetcode.com/problems/length-of-last-word/description/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        length=0
        i=len(s)-1
        while i>-1:
            if s[i]==' ' and length!=0:
                break
            elif s[i]==' ':
                pass
            else:
                length+=1
            i-=1
        return length
