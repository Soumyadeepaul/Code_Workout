#https://www.naukri.com/code360/problems/find-similarities-between-two-arrays_1229070

from os import *
from sys import *
from collections import *
from math import *

def findSimilarity(arr1, arr2, n, m):

    # Write your code here.
    intersection=[]
    for i in arr1:
        for j in arr2:
            if i==j:
                intersection.append(i)
                break
    union=str(n+m-len(intersection))
    return [str(len(intersection)),union]
