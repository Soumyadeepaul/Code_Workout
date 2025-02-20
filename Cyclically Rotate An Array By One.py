from os import *
from sys import *
from collections import *
from math import *

def rotate(arr, n):
    # Write your code here.
    last=arr[n-1]
    for i in range(n-1,0,-1):
        arr[i]=arr[i-1]
    arr[0]=last
    return arr
