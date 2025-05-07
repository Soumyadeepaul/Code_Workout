#https://www.naukri.com/code360/problems/min-steps-to-one-using-dp_920548

from os import *
from sys import *
from collections import *
from math import *

def countStepsToOne(n):
    # Write your code here
    if n==2 or n==3:
        return 1
    if n==1:
        return 0
    dp=[0 for _ in range(n+1)]
    dp[2]=1 #base case
    dp[3]=1 #base case
    i=4
    while i<n+1:
        valx=10*9 +7
        if i%3==0: #if div. by 3, get that value
            idx=i//3
            valx=dp[idx]
        elif i%2==0: #if dev. by 2, get that value
            idx=i//2
            valx=dp[idx]
        dp[i]=min(valx,dp[i-1])+1   #always take the divisible value and possible value by idx-1, like for 10, check with 5 and 9 idx
        i+=1
    return dp[-1]


    # LOGIC
    #     10
    #    /  \
    #   5    9
    #   |   / \
    #   4  3   8
    #  / \ |  / \
    # 2  3   4   7  




    #if 6 go with %3, it will give the minimum and check with 5
