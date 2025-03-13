#https://www.naukri.com/code360/problems/next-permutaion_893046

from os import *
from sys import *
from collections import *
from math import *

def nextPermutation(permutation, n):
    # Write your code here.
    # Return a list.

    #check from reverse
    #[2,3,4(pivot),6,1]   #after 4,, 61 is the max value
    #reverse 6,1 -> [2,3,4,1,6]
    #find the next greater element after pivot... and swap

    #if the number are in desc.... direct reverse



    desc=0
    pivot=0
    for i in range(n-1,0,-1):
        if permutation[i]>permutation[i-1]:
            #not is desc order
            desc=1
            pivot=permutation[i-1]
            # if 2nd last element is pivot... just swap
            if i==len(permutation)-1:
                permutation[i],permutation[i-1]=permutation[i-1],permutation[i]
                break
            rev=permutation[i::]
            rev=rev[::-1]
            permutation=permutation[:i]+rev
            for j in range(i,len(permutation)):
                    if permutation[j]>pivot:
                        #swap with pivot element
                        permutation[i-1],permutation[j]=permutation[j],permutation[i-1]
                        break
            break
    if desc==0:
        permutation=permutation[::-1]
    return permutation
