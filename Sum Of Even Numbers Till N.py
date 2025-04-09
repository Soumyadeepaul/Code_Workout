#https://www.naukri.com/code360/problems/sum-of-even-numbers-till-n_893205

from os import *
from sys import *
from collections import *
from math import *

def evenSumTillN(n):
    # Write your code here.
    totalNumber=n//2
    ap=(totalNumber/2)*((2*2)+(totalNumber-1)*2)
    return int(ap)
