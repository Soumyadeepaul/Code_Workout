#https://www.naukri.com/code360/problem-of-the-day/easy

from os import *
from sys import *
from collections import *
from math import *

def nextGreaterElement(arr, n):
	# Write your code here.
	# result=[]
	# length=len(arr)
	# for i in range(length-1):
	# 	key=arr[i]
	# 	result.append(-1)
	# 	for j in range(i+1,length):
	# 		if key<arr[j]:
	# 			result[i]=arr[j]
	# 			break
	# result.append(-1)
	# return result
	result=[-1]
	length=len(arr)
	for i in range(length-2,-1,-1):
		if arr[i]<arr[i+1]:
			result.append(arr[i+1])
		elif result[len(result)-1]>arr[i]:
			result.append(result[len(result)-1])
		else:
			result.append(-1)
			key=arr[i]
			for j in range(i+1,length):
				if key<arr[j]:
					result[-1]=arr[j]
					break
	return result[::-1]
