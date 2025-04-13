#https://www.naukri.com/code360/problems/inplace-rotate-matrix-90-degree_839734


from os import *
from sys import *
from collections import *
from math import *

def inplaceRotate(mat, n):

    # Write your code here.
    #1. Transpose
    #2. Rotate row

    i=0
    while i<n:
        j=i+1
        while j<n:
            mat[i][j],mat[j][i]=mat[j][i],mat[i][j] 
            j+=1
        i+=1
    for i in range(n//2):
        mat[i],mat[(n-1)-i]=mat[(n-1)-i],mat[i]
    return mat
