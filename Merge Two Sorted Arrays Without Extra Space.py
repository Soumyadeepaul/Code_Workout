#https://www.naukri.com/code360/problems/merge-two-sorted-arrays-without-extra-space_6898839

from typing import *

def mergeTwoSortedArraysWithoutExtraSpace(a : List[int], b : List[int]) -> int:
    # Write your code here.
    i=0
    j=0  #always 1st position
    while i<len(a):
        if a[i]<=b[j]:
            i+=1
        elif a[i]>b[j]: #swap when a's value is greater
            a[i],b[j]=b[j],a[i]
            z=j
            key=b[z]

            #inplace sorting in b array
            while z<len(b)-1:
                if key>b[z+1]:
                    b[z]=b[z+1]
                else:
                    b[z]=key
                    break
                if z+1==len(b)-1:
                    b[z+1]=key
                    break
                z+=1
                

    
