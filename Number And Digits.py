#https://www.naukri.com/code360/problems/number-and-digits_975269

from os import *
from sys import *
from collections import *
from math import *

def numbersAndDigits(n):
    # Write your code here
    # Return the list 
    result=[]
    l=len(str(n))
    for i in range(l,n):
        summ=i
        value=i
        while value:
            summ+=value%10
            value//=10
        if summ==n:
            result.append(i)
    if result:
        return result
    return [-1]


###TLE
