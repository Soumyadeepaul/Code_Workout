#

from os import *
from sys import *
from collections import *
from math import *

def numberofSubarrays(arr, n):
    # Write your code here.
    ones=[]
    zeros=[]
    previous=arr[0]
    count=1
    for i in range(1,n):
        if arr[i]!=previous:
            if previous==1:
                ones.append(count)
            else:
                zeros.append(count)
            previous=arr[i]
            count=1
        else:
            count+=1
    if previous==1:
        ones.append(count)
    else:
        zeros.append(count)
    result=0
    for i in ones:
        result+=(i*(i+1))//2
    for i in zeros:
        result+=(i*(i+1))//2
    return result
    


