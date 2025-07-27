#

from os import *
from sys import *
from collections import *
from math import *

"""

	Here, queries[i] is a list of integer representing the ith query, 
	in which for different type of queries i.e -:
	1. PUSH 'X' -: queries[i][0] = 1, and queries[i][1] = 'X';
	2. POP -: queries[i][0] = 2;
	3. INC 'K', 'Y' -: queries[i][0] = 3, queries[i][1] = 'K' and queries[i][2] = 'Y';
	
"""

def answerQueries(queries, limit):
    # Write your code here.
	stack=[]
	top=0
	result=[]
	for i in queries:
		if i[0]==1:
			if top<limit:
				stack.append(i[1])
				top+=1
		elif i[0]==2:
			if top!=0:
				top-=1
				result.append(stack.pop())
			else:
				result.append(-1)

		else:
			if top<i[1]:
				for x in range(top):
					stack[x]+=i[2]
			else:
				for x in range(i[1]):
					stack[x]+=i[2]
	return result
