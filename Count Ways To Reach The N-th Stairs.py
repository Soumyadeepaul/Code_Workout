#https://www.naukri.com/code360/problems/count-ways-to-reach-nth-stairs_798650

from os import *
from sys import *
from collections import *
from math import *

def countDistinctWays(nStairs: int) -> int:
    #  Write your code here.
    
    def step(n,dp):
        if n==0:
            return 0
        if dp[n]!=0:
            return dp[n]
        cost1=step(n-1,dp)
        cost2=0
        if n>1:
            cost2=step(n-2,dp)
        dp[n]+=cost1+cost2
        return dp[n]    

    if nStairs==0 or nStairs==1:
        return 1
    dp=[0 for _ in range(nStairs+1)]
    dp[1]=1
    dp[2]=2
    return step(nStairs,dp)%1000000007
