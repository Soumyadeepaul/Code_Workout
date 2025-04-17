#https://www.naukri.com/code360/problems/middle-of-three_1118283

from sys import *
from collections import *
from math import *

def middleOfThree(x:int, y:int, z:int):
    # Write your code here
    # Return an integer
    val=(x+y+z)/3
    min1=abs(val-x)
    min2=abs(val-y)
    min3=abs(val-z)
    minn=min(min1,min2,min3)
    if minn==min2:
        return y
    if minn==min1:
        return x
    return z
