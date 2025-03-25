#https://www.naukri.com/code360/problems/longest-subset-zero-sum_920321
###########################
#TLE
###########################
from math import *
from collections import *
from sys import *
from os import *


def LongestSubsetWithZeroSum(arr):

    # Write your Code here.
    # Return an integer denoting the answer.
    ans=0
    prefix=[arr[0]]
    for i in range(1,len(arr)):
        prefix.append(prefix[i-1]+arr[i])
        if prefix[-1]==0:
            ans=len(prefix)
    while len(prefix)>ans:
        #remove 1st element from prefix.. and subtract will rest of the prefix
        #when value in prefix found 0.... store the len of prefix till i'th
        val=prefix.pop(0)
        for i in range(len(prefix)):
            prefix[i]-=val
            if prefix[i]==0 and len(prefix[:i+1])>ans:
                ans=len(prefix[:i+1])
    return ans
