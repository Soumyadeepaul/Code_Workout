#https://www.naukri.com/code360/problems/pair-sum_1171154

from os import *
from sys import *
from collections import *
from math import *

def pairSum(arr, n, target):
    # Write your code here.
    count=0
    i=0
    j=n-1
    while i<j:
        if arr[i]+arr[j]==target:
            i+=1
            j-=1
            count+=1
        elif arr[i]+arr[j]<target:
            i+=1
        else:
            j-=1
    return count if count!=0 else -1
