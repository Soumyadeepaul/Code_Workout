#https://www.naukri.com/code360/problems/find-the-single-element_6680465

from typing import *

def getSingleElement(arr : List[int]) -> int:
    # Write your code here.
    i=1
    while i<len(arr)-2:
        if arr[i]==arr[i+1]:
            i+=2
        elif arr[i]==arr[i-1]:
            i+=1
        else:
            return arr[i]
    return arr[len(arr)-1]
