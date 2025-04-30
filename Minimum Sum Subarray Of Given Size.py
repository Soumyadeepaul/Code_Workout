#https://www.naukri.com/code360/problems/find-minimum-sum-subarray-of-given-size_873368
from os import *
from sys import *
from collections import *
from math import *

def minSubarraySum(arr, n, k):

	# Write your code here
	minn=maxsize
	window=arr[:k]
	for i in range(k,n):
		val=sum(window)
		window.pop(0)
		window.append(arr[i])
		minn=min(val,minn)
	val=sum(window)
	window.pop(0)
	window.append(arr[-1])
	minn=min(val,minn)
	return minn
