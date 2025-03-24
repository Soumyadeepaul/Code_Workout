#https://www.naukri.com/code360/problems/delete-middle-element-from-stack_985246

from os import *
from sys import *
from collections import *
from math import *

def deleteMiddle(inputStack, N):

    # Write your solution here
    def delete(inputStack,mid,N):
        val=inputStack.pop()
        if N==mid:
            return
        delete(inputStack,mid,N-1)
        inputStack.append(val)
    
    mid=(N//2)+1
    if N%2==0:
        mid-=1
    return delete(inputStack,mid,N)
