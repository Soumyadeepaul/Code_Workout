#https://www.naukri.com/code360/problem-of-the-day/easy

from os import *
from sys import *
from collections import *
from math import *

def findSetBit(N):   
    # Write your code here
    count=0
    pos=0
    ans=-1
    while N:
        binary=N%2
        N=N//2
        pos+=1
        if binary==1 and count!=0:
            return -1
        elif binary==1:
            ans=pos
            count=1
    return ans
