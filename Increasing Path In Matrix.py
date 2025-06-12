#

from os import *
from sys import *
from collections import *
from math import *

def longestIncreasingPath(mat, n, m):
    # Write your code here

    
    def paths(mat,i,j,n,m,length,result):
        result=max(result,length)
        if i+1<n and j+1<m:
            if mat[i+1][j]>mat[i][j]:
                result=paths(mat,i+1,j,n,m,length+1,result)
            if mat[i][j+1]>mat[i][j]:
                result=paths(mat,i,j+1,n,m,length+1,result)
        elif i+1<n and j+1==m:
            if mat[i+1][j]>mat[i][j]:
                result=paths(mat,i+1,j,n,m,length+1,result)
        elif i+1==n and j+1<m:
            if mat[i][j+1]>mat[i][j]:
                result=paths(mat,i,j+1,n,m,length+1,result)
        mat[i][j]=-10**9+7  #SIGNIFIES the index already explored
        return result

    return paths(mat,0,0,n,m,1,1)
