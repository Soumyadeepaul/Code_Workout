#https://www.naukri.com/code360/problems/number-pattern_893194

from os import *
from sys import *
from collections import *
from math import *

def numberPattern(n):

	# Write your code here.
	result=[]
	for i in range(n,0,-1):
		string=''
		for j in range(1,i+1):
			string+=str(j)
		result.append(string)
	return result
