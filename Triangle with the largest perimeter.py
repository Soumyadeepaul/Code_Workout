#https://www.naukri.com/code360/problems/triangle-with-the-largest-perimeter_1463974

from os import *
from sys import *
from collections import *
from math import *

def maxPerimeterTriangle(arr,  n):
    
    # Write your code here.
    arr=sorted(arr)
    for i in range(n-1,1,-1):
        if arr[i]<arr[i-1]+arr[i-2]:
            return arr[i]+arr[i-1]+arr[i-2]
    return 0
