#https://leetcode.com/problems/merge-strings-alternately/description/?envType=study-plan-v2&envId=leetcode-75
#MERGE SORT TECHNIQUE
class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        result=''
        i=0
        j=0
        alternative=1
        while i<len(word1) and j<len(word2):
            if alternative==1:
                result+=word1[i]
                i+=1
                alternative=2
            elif alternative==2:
                result+=word2[j]
                j+=1
                alternative=1
        while i<len(word1):
            result+=word1[i]
            i+=1
        while j<len(word2):
            result+=word2[j]
            j+=1
        return result
        
