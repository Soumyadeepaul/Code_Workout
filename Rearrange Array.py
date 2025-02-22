#https://www.naukri.com/code360/problem-of-the-day/easy

from os import *
from sys import *
from collections import *
from math import *

def rearrangeArray(arr, n):
    # Write you code here
    # result=[]
    # for i in range(n):
    #     value=arr[arr[i]]
    #     result.append(value)
    # for i in range(n):
    #     arr[i]=result[i]

    #......................
    #encoding 2 number into 1
    #4  0100
    #3  0011
    #resultant 00110100
    for i in range(n):
        arr[i]="_"+str(bin(arr[i]))
    for i in range(n):
        value=arr[int(arr[i][1:],2)].split("_")[1]
        arr[i]=value+arr[i]
    for i in range(n):
        arr[i]=int(arr[i].split('_')[0],2)
