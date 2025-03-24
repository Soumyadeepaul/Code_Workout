#https://www.naukri.com/code360/problem-of-the-day/moderate

from os import *
from sys import *
from collections import *
from math import *

from typing import List


def minimumCost(n: int, s: str, cost: List[int]) -> int:
    # write your code here
    s=list(s)
    i=0
    costing=0
    while i<n-1:
        if s[i]==s[i+1]:
            s.pop(i)
            if len(cost)>i+1 and cost[i]>cost[i+1]:
                val=cost.pop(i+1)
                costing+=val
            elif len(cost)>i:
                val=cost.pop(i)
                costing+=val
            n-=1
        else:
            i+=1
    return costing
