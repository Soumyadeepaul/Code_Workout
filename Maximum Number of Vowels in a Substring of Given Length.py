#https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        #Sliding window
        window=[]
        vowel=0
        #vowels=['a','e','i','o','u']
        vowels='aeiou'
        for i in range(k):
            alpha=s[i]
            window.append(alpha)
            if alpha in vowels:
                vowel+=1
        maxVowel=vowel
        for i in range(k,len(s)):
            alphaExit=window.pop(0)
            alphaEntry=s[i]
            window.append(alphaEntry)
            if alphaExit in vowels:
                vowel-=1
            if alphaEntry in vowels:
                vowel+=1
            maxVowel=max(maxVowel,vowel)
        return maxVowel
