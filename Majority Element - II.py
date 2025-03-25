#https://www.naukri.com/code360/problem-of-the-day/easy

from math import *
from collections import *
from sys import *
from os import *

# def majorityElementII(arr):
# 	# Write your code here.
# 	strict=len(arr)//3
# 	ar=Counter(arr)
# 	anss=[]
# 	for i in ar:
# 		if ar[i]>strict:
# 			anss.append(i)
# 	return anss

##################################################################
def majorityElementII(arr):
	# Write your code here.
	strict=len(arr)//3
	result={}
	ans=set()
	for i in arr:
		if i not in result:
			result[i]=1
		else:
			result[i]+=1
		if result[i]>strict:
			ans.add(i)
	return list(ans)
