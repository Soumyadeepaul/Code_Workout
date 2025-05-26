#

from os import *
from sys import *
from collections import *
from math import *

def findAllSelfDividingNumbers(lower, upper):

    # Write your code here
    # This function returns a list of all the self-dividing numbers in the range [left, right]
    result=[]
    for i in range(lower,upper+1):
        val=i
        while val:
            rem=val%10
            if rem!=0:
                if i%(rem)==0:
                    val//=10
                else:
                    break
            else:
                break
        if val==0:
            result.append(i)
    return result
