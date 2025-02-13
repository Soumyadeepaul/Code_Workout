#https://www.naukri.com/code360/problems/largest-element-in-the-array-largest-element-in-the-array_5026279

from sys import *
from collections import *
from math import *

def largestElement(arr: [], n: int) -> int:

    # Write your code from here.
    largest=-maxsize
    for i in arr:
        if i>largest:
            largest=i
    return largest
