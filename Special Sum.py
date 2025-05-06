#

from os import *
from sys import *
from collections import *
from math import *

def specialSum(arr, n):
	# Write your code here. 
	minn=10**9+7
	val1=0
	val2=0
	for i in range(n):
		val1+=arr[i]
		val2+=arr[n-i-1]
		minn=min(minn,val1+val2)
	return minn
