#https://www.naukri.com/code360/problems/total-unique-paths_1081470

from collections import *
from math import *

def uniquePaths(m, n):
	# Write your code here.

	#TC: O(m*n)
	#SC: O(m)
	dp=[0 for i in range(m+1)] #1 extra space for out of range value to be 0
	dp[m-1]=1  #finishing point is taken as value 1
	while n!=0:
		for i in range(m-1,-1,-1):
			dp[i]=dp[i]+dp[i+1]
		n-=1
	return dp[0]
