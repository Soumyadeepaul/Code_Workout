#https://www.naukri.com/code360/problems/insertion-sort_3155179

from os import *
from sys import *
from collections import *
from math import *

from typing import List

def insertionSort(n: int, arr: List[int]) -> None:
    # Write your code here.
    i=1
    while i<n:
        key=arr[i]
        j=i-1
        while j>-1 and arr[j]>key:
            arr[j+1]=arr[j]
            j-=1
        arr[j+1]=key
        i+=1
