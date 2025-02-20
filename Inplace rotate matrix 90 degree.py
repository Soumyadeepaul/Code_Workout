
from os import *
from sys import *
from collections import *
from math import *

def inplaceRotate(inputArray, n):

    # Write your code here.
    result=[]
    for j in range(n-1,-1,-1):
        lis=[]
        for i in range(n):
            lis.append(inputArray[i][j])
        result.append(lis)
    return result

