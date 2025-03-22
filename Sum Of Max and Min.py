#https://www.naukri.com/code360/problems/sum-of-max-and-min_1081476

from os import *
from sys import *
from collections import *
from math import *

def sumOfMaxMin(arr):
    # Write your code here
    maxx=-maxsize
    minn=maxsize
    for i in arr:
        if maxx<i:
            maxx=i
        if minn>i:
            minn=i
    return maxx+minn
