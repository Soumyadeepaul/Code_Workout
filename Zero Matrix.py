#https://www.naukri.com/code360/problems/zero-matrix_1171153

from sys import *
from collections import *
from math import *

def zeroMatrix(matrix, n, m):
    # Write your code here.
    for i in range(n):
        for j in range(m):
            if matrix[i][j]==0:
                for a in range(m):
                    if matrix[i][a]==0:
                        pass
                    else:
                        matrix[i][a]=-1
                for a in range(n):
                    if matrix[a][j]!=0:
                        matrix[a][j]=-1
    for i in range(n):
        for j in range(m):
            if matrix[i][j]==-1:
                matrix[i][j]=0
    return matrix
