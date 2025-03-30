#https://www.naukri.com/code360/problems/longest-mountain-subarray_893069

from os import *
from sys import *
from collections import *
from math import *

def longestMountain(arr, n):

    # Write your code here.
    longest=0
    i=1
    presentPeak=0
    while i<n-1:
        if arr[i]!=1 and (arr[i]>arr[i-1] and arr[i]>arr[i+1]): #condition for peak element
            presentPeak=arr[i]  #let it be the peak element
            j=i-1
            z=i+1
            count=0
            while j>-1 and arr[j]<arr[j+1]:
                count+=1
                j-=1
            while z<n and arr[z]<arr[z-1]: 
                count+=1
                z+=1
            if longest<count+1 and count!=0:
                longest=count+1
        i+=1
    return longest
