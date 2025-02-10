#https://www.naukri.com/code360/problems/first-and-last-position-of-an-element-in-sorted-array_1082549

from os import *
from sys import *
from collections import *
from math import *

def firstAndLastPosition(arr, n, k):

    # Write your code here
    result=[-1,-1]
    z=0
    for i in range(0,n):
        if arr[i]==k:
            z=1
            result[0]=i
            result[1]=i
        if z==1:
            for j in range(i,n):
                if arr[j]==k:
                    result[1]=j
            break
    return result
