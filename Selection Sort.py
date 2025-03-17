#https://www.naukri.com/code360/problems/selection-sort_981162

from os import *
from sys import *
from collections import *
from math import *

def selectionSort(arr,n):
    # Write your code here
    # Do not return anything. Update the given array in-place
    for i in range(0,n):
        smallYet=i
        for j in range(i,n):
            if arr[smallYet]>arr[j]:
                smallYet=j
        arr[smallYet],arr[i]=arr[i],arr[smallYet]
    return arr
