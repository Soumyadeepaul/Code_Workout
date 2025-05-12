#https://www.naukri.com/code360/problems/print-permutations-string_758958

from os import *
from sys import *
from collections import *
from math import *

def findPermutations(s):
	# Write your code here.
	s=list(s)

	def permute(s,result,idx):
		if idx==len(s):
			result.append(''.join(s))
			return result
		for i in range(idx,len(s)):
			s[idx],s[i]=s[i],s[idx]
			result=permute(s,result,idx+1)
			s[idx],s[i]=s[i],s[idx]
		return result
	return permute(s,[],0)
