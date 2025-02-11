#https://www.naukri.com/code360/problems/intersection-of-2-arrays_1082149

from os import *
from sys import *
from collections import *
from math import *

def output(arr,brr,n,m):
    result=[]
    j=0
    for i in range(n):
        while j<len(brr):
            if arr[i]==brr[j]:
                result.append(arr[i])
                brr.pop(j)
                break
            elif arr[i]<brr[j]:
                break
            j+=1
    return result

def findArrayIntersection(arr: list, n: int, brr: list, m: int):
    # Write your code here
    # Return a list containing all the common elements in arr and brr.
    if n>=m:
        return output(brr,arr,m,n)
    else:
        return output(arr,brr,n,m)

