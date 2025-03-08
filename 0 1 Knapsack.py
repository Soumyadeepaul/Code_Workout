#https://www.naukri.com/code360/problems/0-1-knapsack_920542


from os import *
from sys import *
from collections import *
from math import *

## Read input as specified in the question.
## Print output as specified in the question.

n=int(input())
for i in range(n):
    length=int(input())
    w=list(map(int,input().split()))
    p=list(map(int,input().split()))
    sack=int(input())
    if sum(w)<=sack:
        print(sum(p))
    else:
        minn_ind=0
        w_new=[]
        p_new=[]
        for _ in range(length):
            for j in range(length):
                if w[j]<w[minn_ind]:
                    minn_ind=j
            w_new.append(w[minn_ind])
            p_new.append(p[minn_ind])
            w[minn_ind]=99999


        dp=[[0 for _ in range(sack+1)] for _ in range(length+1)]

        for i in range(1,length+1):
            for j in range(1,sack+1):
                if w_new[i-1]<=j:
                    dp[i][j]=max(p_new[i-1]+dp[i-1][j-w_new[i-1]],dp[i-1][j])
                else:
                    dp[i][j]=dp[i-1][j]
        print(dp[len(dp)-1][len(dp[0])-1])
