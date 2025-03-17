#https://www.naukri.com/code360/problems/get-path-dfs_2033590

from os import *
from sys import *
from collections import *
from math import *

def getPath(V, E, a, b, v1, v2):
    # Write your code here.
    #visited is used for avoiding cycle
    visited=[0 for _ in range(V)]
    #stack is used in dfs
    stack=[v1]
    #result
    ans=[]
    #starting vertix is visited
    visited[v1]=1
    #as undirected graph 1 to 2   and 2 to 1 is also possible
    l=a
    a=a+b
    b=b+l
    while stack:
        #DFS
        top=stack[-1]
        for i in range(len(a)):
            #check for the edge
            if top==a[i]:
                #if vertix is not visited
                if visited[b[i]]==0:
                    #push in stack
                    stack.append(b[i])
                    #mark as visited
                    visited[b[i]]=1
        #if no new element has been inserted in stack, then pop that element
        #as it is being fully explored
        if top==stack[-1]:
            ans.append(stack.pop())
    if v2 in ans:
        return ans
    return []

