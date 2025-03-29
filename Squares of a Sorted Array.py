#https://www.naukri.com/code360/problems/squares-of-a-sorted-array_1230552

from os import *
from sys import *
from collections import *
from math import *

def sqsorted(arr):
	# Write your code here.
	result=[]
	for i in arr:
		val=i*i
		result.append(val)
	return sorted(result)
