#https://www.naukri.com/code360/problems/longest-consecutive-sequence_759408

from math import *
from collections import *
from sys import *
from os import *

def lengthOfLongestConsecutiveSequence(arr, n):
    # Write your code here.
    arr=sorted(arr)
    result=1
    count=1
    for i in range(1,n):
        if arr[i]-arr[i-1]==1:
            count+=1
        elif arr[i]==arr[i-1]:
            pass
        else:
            count=1
        result=max(result,count)
    return result
