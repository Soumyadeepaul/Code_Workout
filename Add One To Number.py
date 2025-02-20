from os import *
from sys import *
from collections import *
from math import *

def addOneToNumber(arr):
    #   Write your code here
    carry=1
    for i in range(len(arr)-1,-1,-1):
        arr[i]=arr[i]+carry
        carry=arr[i]//10
        arr[i]=arr[i]%10
    if carry==1:
        arr.insert(0,carry)
    for i in range(len(arr)):
        if arr[i]!=0:
            return arr[i:]
