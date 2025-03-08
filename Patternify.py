#https://www.naukri.com/code360/problem-of-the-day/easy

from os import *
from sys import *
from collections import *
from math import *

def printPatt(n):
	
	# Write your code here.
	ans=[]
	for i in range(n,0,-1):
		l=''
		for _ in range(i):
			l+='*'
		ans.append(l)
	return ans
