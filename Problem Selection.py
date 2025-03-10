#https://www.naukri.com/code360/problems/problem-selection_2824965

from sys import *
from collections import *
from math import *

from typing import *

def problemSelection(A: List[int], K: int)-> tuple[int, int]:
    # Write your code here.
    minn=0
    maxx=0
    arr=sorted(A)
    i=0
    copy_arr=arr[::-1]
    while i<len(arr):
        minn+=arr[i]
        i=i+1
        if len(arr)<=K:
            arr=[]
        else:
            arr=arr[:len(arr)-K]
    i=0
    while i<len(copy_arr):
        maxx+=copy_arr[i]
        i=i+1
        if len(copy_arr)<=K:
            copy_arr=[]
        else:
            copy_arr=copy_arr[:len(copy_arr)-K]
    return minn,maxx
