#

from os import *
from sys import *
from collections import *
from math import *

def ninjaAndTriangle(n):
    # Write your code here.
    # i=1
    # result=0
    # while n:
    #     if n-i>-1:
    #         n=n-i
    #         result+=1
    #         i+=1
    #     else:
    #         break
    # return result

    
    start=0
    end=n//2

    while start<=end:
        mid=start+(end-start)//2
        val=(mid*(mid+1))//2
        if val<=n:
            result=mid
            start=mid+1
        else:
            end=mid-1
    return result
        
