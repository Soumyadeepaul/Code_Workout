#https://www.naukri.com/code360/problems/edit-distance_630420

from sys import stdin
import sys
sys.setrecursionlimit(10**7) 
def editDistance(str1, str2) :
    
    # Your code goes here

    #[[0,1,2,3,4]
    # [1,0,0,0,0]
    # [2,0,0,0,0]]
    dp=[[0 for _ in range(len(str1)+1)] for _ in range(len(str2)+1)]
    for j in range(len(str1)+1):
        dp[0][j]=j
    for i in range(len(str2)+1):
        dp[i][0]=i
    for i in range(1,len(str2)+1):
        for j in range(1,len(str1)+1):
            #if same, copy diagonal
            if str1[j-1]==str2[i-1]:
                dp[i][j]=dp[i-1][j-1]
            else:
                #if not same, minimum of 3 important box +1
                dp[i][j]=min(dp[i-1][j-1],dp[i][j-1],dp[i-1][j])+1
    return dp[len(str2)][len(str1)]
