# NOT OPTIMAL

from os import *
from sys import *
from collections import *
from math import *

def ninjaCity(mat):

    # Write your Code Here.
    # Return a 2-d list of integers
    l=len(mat[0])-1
    l1=len(mat)-1
    half=l//2
    mid=(l1//2)+1
    if l1==0:
        return [mat[0][::-1]]

    for i in range(mid):
        for j in range(0,half+1):
            mat[i][j],mat[i][l-j]=mat[i][l-j],mat[i][j]
            if l1//2!=l1-i: #MIDDLE ROW MUST NOT REVERSE TWICE
                mat[l1-i][j],mat[l1-i][l-j]=mat[l1-i][l-j],mat[l1-i][j]
    return mat
