from os import *
from sys import *
from collections import *
from math import *

import sys
from sys import stdin

def spiralPathMatrix(matrix, n, m):
    # Write your code here.
    top=0
    bottom=n
    left=0
    right=m
    result=[]
    i=0
    while top<bottom and left<right: #till top less than bottom and left less than right
        #######################################
        for j in range(left,right):
            result.append(matrix[i][j])
        top+=1   #shifting top
        j=right-1
        #######################################
        for i in range(top,bottom):
            result.append(matrix[i][j])
        right-=1 #shifting right
        #######################################
        if top==bottom or left==right: #corner case for odd length matrix
            break 
        #######################################
        for j in range(right-1,left-1,-1):
            result.append(matrix[i][j])
        bottom-=1 #shiftinh bottom
        j=left
        #######################################
        for i in range(bottom-1,top-1,-1):
            result.append(matrix[i][j])
        left+=1 #shifting left
        j+=1
        
    return result





t = int(input().strip())

for j in range(t):
    
    n, m = list(map(int, stdin.readline().strip().split(" ")))
    
    arr = []
    
    for i in range(n):
        
        a = list(map(int, stdin.readline().strip().split(" ")))
        arr.append(a)
            
    
    for i in spiralPathMatrix(arr, n, m):
        print(i, end = " ")
        
    print()
