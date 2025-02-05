#https://www.naukri.com/code360/problems/pair-sum_697295

from os import *
from sys import *
from collections import *
from math import *

def pairSum(arr, s):
    # Write your code here.
    #arr=sorted(arr)
    #practise of selection sort
    for i in range(0,len(arr)-1):
        minn=i
        for j in range(i+1,len(arr)):
            if arr[minn]>arr[j]:
                minn=j
        if i!=minn:
            arr[minn]=arr[minn]+arr[i]
            arr[i]=arr[minn]-arr[i]
            arr[minn]=arr[minn]-arr[i]
    #print(arr)


    result=[]
    for i in range(0,len(arr)-1):
        for j in range(i+1,len(arr)):
            if arr[i]+arr[j]==s:
                if arr[i]<=arr[j]:
                    result.append([arr[i],arr[j]])
                else:
                    result.append([arr[j],arr[i]])
    return result
