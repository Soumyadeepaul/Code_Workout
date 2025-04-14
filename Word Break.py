#https://www.naukri.com/code360/problems/word-break_1094901

from os import *
from sys import *
from collections import *
from math import *

def wordBreak(dictionary, n, s):
    # Write your code here.
    maxLength=0
    for i in dictionary:
        if maxLength<len(i):
            maxLength=len(i)
    s=' '+s     
    dp=[0 for _ in range(len(s))]
    dp[0]=1
    i=1
    while i<len(s):
        j=i
        wordCount=maxLength
        while j>0:
            if s[j:i+1] in dictionary:
                if dp[j-1]==1:
                    dp[i]=1
                    break
            wordCount-=1
            if wordCount==0:
                break
            j-=1
        i+=1
    return dp[len(s)-1]
