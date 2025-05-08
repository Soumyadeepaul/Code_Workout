#
from os import *
from sys import *
from collections import *
from math import *

def rowWaveForm(mat):
    # Write your code here.
    result=[]
    i=0
    while i<len(mat):
        if i%2==0:
            j=0
            while j<len(mat[0]):
                result.append(mat[i][j])
                j+=1
        else:
            j=len(mat[0])-1
            while j>-1:
                result.append(mat[i][j])
                j-=1
        i+=1
    return result
