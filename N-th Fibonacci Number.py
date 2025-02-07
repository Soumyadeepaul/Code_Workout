#https://www.naukri.com/code360/problems/nth-fibonacci-number_1115780

from os import *
from sys import *
from collections import *
from math import *
series=[1,1]
def fibonacciNumber(n):
    # Write your code here.
    if n-1<len(series):
        return series[n-1]
    for i in range(len(series),n):
        series.append((series[i-1]+series[i-2])%(10**9+7))
    
    return series[n-1]
