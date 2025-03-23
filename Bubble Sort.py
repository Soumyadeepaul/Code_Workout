#https://www.naukri.com/code360/problems/bubble-sort_624380

from typing import List

def bubbleSort(arr: List[int], n: int):
    # Your code goes here.
    for i in range(n):
        swapped=False
        for j in range(0,n-1):
            if arr[j]>arr[j+1]:
                arr[j],arr[j+1]=arr[j+1],arr[j]
                swapped=True
        if swapped==False:
            break
