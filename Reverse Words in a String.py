#https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def reverseWords(self, s: str) -> str:
        result=''
        i=0
        j=0
        while i<len(s):
            while i<len(s) and s[i]==' ':
                i+=1
            j=i
            while j<len(s) and s[j]!=' ':
                j+=1
            ending=j
            j-=1
            while j>=i:
                result=s[j]+result
                j-=1
            result=' '+result
            i=ending+1
        i=0
        while i<len(result):
            if result[i]==' ':
                i+=1
            else:
                break
        return result[i:]
            

        
