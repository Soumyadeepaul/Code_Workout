#

from os import *
from sys import *
from collections import *
from math import *

def generateBinaryNumbers(n):
    # Write your code here
    # Return a list of strings
    binary=[0,1]

    for i in range(2,n+1):
        x=0
        if i&1:
            x=1
        binary.append(binary[i>>1]*10+x)
    return binary[1:]
