#https://www.naukri.com/code360/problems/subset-sum-equal-to-k_1550954

from os import *
from sys import *
from collections import *
from math import *

def subsetSumToK(n, k, arr):

    # Write your code here
    # Return a boolean variable 'True' or 'False' denoting the answer
    arr=sorted(arr)
    dp=[[0 for _ in range(k+1)] for _ in range(n+1)]
    for i in range(1,n+1):
        for j in range(1,k+1):
            if j==arr[i-1]:
                dp[i][j]=1
            elif j<arr[i-1]:
                dp[i][j]=dp[i-1][j]
            else:
                if dp[i-1][j]==1:
                    dp[i][j]=1
                else:
                    index=j-arr[i-1]
                    dp[i][j]=dp[i-1][index]
    if dp[n][k]==1:
        return True
    return False
