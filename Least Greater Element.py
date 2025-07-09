#

from os import *
from sys import *
from collections import *
from math import *

def leastGreaterElement(arr):
    #    Write your code here.
    stack=[]
    result=[]
    for i in range(len(arr)-1,-1,-1):
        if not stack:
            stack.append(arr[i])
            result.append(-1)
        else:
            found=0
            for j in range(len(stack)):
                if stack[j]>arr[i]:
                    found=1
                    result.append(stack[j])
                    stack.append(arr[i])
                    break
            if found==0:
                result.append(-1)
                stack.append(arr[i])
            stack.sort()
    return result[::-1]
