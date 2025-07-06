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
    #find the next greater element after pivot... and swap with pivot

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



#################################################################################
#https://leetcode.com/problems/next-permutation/

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        pivot=0
        i=len(nums)-1
        previous=-10**9+7
        while i>-1:
            if nums[i]>=previous:
                previous=nums[i]
            else:
                pivot=i
                break
            i-=1
        if i==-1:
            start=0
            end=len(nums)-1
            while start<end:
                nums[start],nums[end]=nums[end],nums[start]
                start+=1
                end-=1
        else:
            start=pivot+1
            end=len(nums)-1
            while start<end:
                nums[start],nums[end]=nums[end],nums[start]
                start+=1
                end-=1
            for i in range(pivot+1,len(nums)):
                if nums[i]>nums[pivot]:
                    nums[pivot],nums[i]=nums[i],nums[pivot]
                    break
            

                
