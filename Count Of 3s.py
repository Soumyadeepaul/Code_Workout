#

from os import *
from sys import *
from collections import *
from math import *

def countOf3(x):
    # Write your code here.
    count=0
    for i in range(0,x+1):
        while i:
            if i%10==3:
                count+=1
            i=i//10
    return count
