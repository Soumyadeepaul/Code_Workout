#https://www.naukri.com/code360/problems/rat-in-a-maze_1215030

from os import *
from sys import *
from collections import *
from math import *

def searchMaze(arr, n):
    # Write your code here.
    
    #DFS
    def ways(arr,stack,result,i,j,visited):
        #base case
        if i<0 or j<0 or j>=len(arr[0]) or i>=len(arr):
            return (stack,result) 
        #if 0 can't use that path
        if arr[i][j]==0:
            return (stack,result)
        #destination
        if i==len(arr)-1 and j==len(arr[0])-1:
            if stack not in result:
                result.append(stack)
            return (stack,result)
        
        #if visited don't go through that path
        if visited[i][j]==1:
            return (stack,result) 

        #mark visited 
        visited[i][j]=1    
        
        down,result=ways(arr,stack+'D',result,i+1,j,visited)
        left,result=ways(arr,stack+'L',result,i,j-1,visited)
        right,result=ways(arr,stack+'R',result,i,j+1,visited)
        up,result=ways(arr,stack+'U',result,i-1,j,visited)

        
        #mark visited=0 to use it for some other path -> backtracking
        visited[i][j]=0
        return (stack,result)

    result=[]
    visited=[[0 for _ in range(len(arr[0]))]for _ in range(len(arr))]
    _,result=ways(arr,'',result,0,0,visited)
    return result
