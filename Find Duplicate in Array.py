#https://www.naukri.com/code360/problems/find-duplicate-in-array_1112602

from sys import *
from collections import *
from math import *

def findDuplicate(arr:list, n:int):
    # Write your code here.
    # Returns an integer.
    #bubble sort
    while True:
        swapped=0
        i=0
        while i<n-1:
            if arr[i]>arr[i+1]:
                arr[i]+=arr[i+1]
                arr[i+1]=arr[i]-arr[i+1]
                arr[i]=arr[i]-arr[i+1]
                swapped=1
            i+=1
        if swapped==0:
            break
    for i in range(n-1):
        if arr[i]==arr[i+1]:
            return arr[i]

