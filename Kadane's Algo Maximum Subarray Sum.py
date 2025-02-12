#https://www.naukri.com/code360/problems/maximum-subarray-sum_630526

from os import *
from sys import *
from collections import *
from math import *

from sys import stdin,setrecursionlimit
setrecursionlimit(10**7)
def maxSubarraySum(arr, n) :
    #KADANE's ALGO
	# Your code here
    maxSum=-maxsize
    currSum=0
    for i in range(n):
        currSum+=arr[i]
        if currSum<0:
            currSum=0
        maxSum=max(currSum,maxSum)
        #<0 check after maxsum because of all '-' values in array
        # if currSum<0:
        #     currSum=0

    # return the answer
    return maxSum































#taking inpit using fast I/O
def takeInput() :
	
    n =  int(input())

    if(n == 0) :
        return list(), n

    arr = list(map(int, stdin.readline().strip().split(" ")))

    return arr, n


#main
arr, n = takeInput()
print(maxSubarraySum(arr, n))
