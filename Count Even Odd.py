
from os import *
from sys import *
from collections import *
from math import *
def countEvenOdd(arr, n):    
    # Write your code here.
    result=[0,0]
    count=Counter(arr)
    for i in count:
        if count[i]%2==0:
            result[1]+=1
        else:
            result[0]+=1
    return result
