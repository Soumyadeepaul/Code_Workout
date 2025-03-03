#https://www.naukri.com/code360/problems/missing-and-repeating-numbers_873366

from math import *
from collections import *
from sys import *
from os import *

def missingAndRepeating(arr, n):
    # Write your code here
    lis=[i for i in range(1,n+1)]
    result=[]
    for i in arr:
        j=0
        found=0
        while j<n:
            if i==lis[j]:
                lis.pop(j)
                n-=1
                found=1
                break
            j+=1
        if found==0:
            result.append(i)

    result.insert(0,lis[0])
    return result
