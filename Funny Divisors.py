#https://www.naukri.com/code360/problem-of-the-day/easy

from os import *
from sys import *
from collections import *
from math import *

def findSum(n, arr):

    # Write your Code Here.
    # Return an integer denoting the answer
    ans=0
    while arr:
        val=arr.pop()
        if val%2==0:
            ans+=val
        elif val%3==0:
            ans+=val
    return ans
