#https://www.naukri.com/code360/problems/sort-0-1-2_631055

from os import *
from sys import *
from collections import Counter
from math import *

from sys import stdin,setrecursionlimit
setrecursionlimit(10**7)

def sort012(arr, n) :

	# write your code here
    # don't return anything 
    # using insertion sort
    # for i in range(1,n):
    #     j=i-1
    #     key=arr[i]
    #     while j>=0 and arr[j]>key:
    #         arr[j+1]=arr[j]
    #         j-=1
    #     arr[j+1]=key

    collect=Counter(arr)
    for i in range(n):
        if collect[0]!=0:
            arr[i]=0
            collect[0]-=1
        elif collect[1]!=0:
            arr[i]=1
            collect[1]-=1
        elif collect[2]!=0:
            arr[i]=2
            collect[2]-=1
