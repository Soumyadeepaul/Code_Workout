#https://www.naukri.com/code360/problems/left-rotate-an-array-by-one_5026278

from sys import *
from collections import *
from math import *

def rotateArray(arr: [], n: int) -> []:
    # Write your code from here.
    start_value=arr[0]
    for i in range(1,n):
        arr[i-1]=arr[i]
    arr[n-1]=start_value
    return arr
