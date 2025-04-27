#

from os import *
from sys import *
from collections import *
from math import *

def theOrder(n):
	# Write your code here.
	result=[]
	initial=[i for i in range(1,n+1)]
	count_neg_one=len(initial)
	count=0
	i=1
	skip=0
	while i<len(initial):
		if initial[i]!=-1 and skip==1:
			skip=0
		elif initial[i]!=-1 and skip!=1:
			result.append(initial[i])
			initial[i]=-1
			skip=1
			count+=1
		i+=1
		i=i%len(initial) #circular queue

		if count==count_neg_one:
			break
	return result
