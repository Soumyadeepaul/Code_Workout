#https://www.naukri.com/code360/problems/longest-palindromic-subsequence_842787

from os import *
from sys import *
from collections import *
from math import *

def longestPalindromeSubsequence(s):
    # Write your code here.
    dp=[[0 for _ in range(len(s))] for _ in range(len(s))]
    i=-1
    start=0
    l=len(s)
    while i<l:
        for j in range(start,len(s)):
            i+=1
            if i==j:
                dp[i][j]=1
            elif s[i]==s[j]:
                dp[i][j]=2+dp[i+1][j-1]
            else:
                dp[i][j]=max(dp[i][j-1],dp[i+1][j])
        start+=1
        i=-1
        l-=1
    return dp[0][len(s)-1]
