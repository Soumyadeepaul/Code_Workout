#https://www.naukri.com/code360/problems/reverse-the-array_1262298

from os import *
from sys import *
from collections import *
from math import *

def reverseArray(arr, m):
    # Write your code here.
    position=1
    for i in range(m+1,len(arr)):
        if i<len(arr)-position:
            t=arr[i]
            arr[i]=arr[len(arr)-position]
            arr[len(arr)-position]=t
            position+=1
        else:
            break
    return arr
