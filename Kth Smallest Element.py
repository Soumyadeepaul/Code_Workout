#https://www.naukri.com/code360/problems/kth-smallest-element_893056

from os import *
from sys import *
from collections import *
from math import *
from heapq import heapify,heappop
def kthSmallest(n,k,arr):
    # Write your code here.
    heapify(arr)
    while k!=1:
        heappop(arr)
        k-=1
    return heappop(arr)
