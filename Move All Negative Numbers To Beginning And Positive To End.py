#https://www.naukri.com/code360/problems/move-all-negative-numbers-to-beginning-and-positive-to-end_1112620

from os import *
from sys import *
from collections import *
from math import *

def separateNegativeAndPositive(nums):
    # write your code here
    first=0
    last=len(nums)-1
    while first<last:
        if nums[first]<0:
            first+=1
        elif nums[last]>0:
            last-=1
        else:
            nums[first],nums[last]=nums[last],nums[first]
    return nums
