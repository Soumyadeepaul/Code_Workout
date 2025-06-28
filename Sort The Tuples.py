#

from os import *
from sys import *
from collections import *
from math import *

from typing import *

def sortTuples(arr : List[List[int]]):
    # Write your code here.
    result=[]
    indexs=[]
    l=len(arr[0])-1
    while arr:
        minn=10**9+7
        for i in range(len(arr)):
            if arr[i][-1]<minn:
                minn=arr[i][-1]
                indexs=[i]
            elif arr[i][-1]==minn:
                indexs.append(i)
        m=min(indexs)
        result.append(arr[m])
        arr.pop(m)
    for i in result:
        arr.append(i)
        
