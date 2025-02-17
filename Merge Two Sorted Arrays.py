#https://www.naukri.com/code360/problems/ninja-and-sorted-arrays_1214628

from math import *
from collections import *
from sys import *
from os import *
# def move_back(arr,index):
#     for i in range(len(arr)-1,index,-1):
#         arr[i]=arr[i-1]
#     return arr

def ninjaAndSortedArrays(arr1,arr2,m,n):
#     # Write your code here.
#     index_complete=0
#     while arr2:
#         value=arr2.pop(0)
#         for i in range(index_complete,len(arr1)):
#             index_complete=i+1
#             if value<arr1[i]:
#                 arr1=move_back(arr1,i)
#                 arr1[i]=value
#                 break
#             elif arr1[i]==0:
#                 arr1[i]=value
#                 break
#     return arr1
    arr1=arr1[:m]
    arr1.extend(arr2)
    return sorted(arr1)

