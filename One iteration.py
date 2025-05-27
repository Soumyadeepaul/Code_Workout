#

from sys import *
from collections import *
from math import *
from heapq import heapify, heappop,heappush
from typing import *

def oneIteration(A: List[int]) -> int:
    # Write your code here.
    arr=[]
    heapify(arr)
    for i in A:
        heappush(arr,-i)
    
    return -(heappop(arr)+heappop(arr))
