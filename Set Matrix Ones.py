#https://www.naukri.com/code360/problem-of-the-day/easy

from sys import *
from collections import *
from math import *

def setMatrixOnes(MAT, n, m):

	# Write your code here
	position=[]
	for i in range(n):
		for j in range(m):
			if [i,j] in position:
				pass
			elif MAT[i][j]==1:
				for z in range(m):
					if MAT[i][z]==0:
						if [i,z] not in position:
							position.append([i,z])
					MAT[i][z]=1
				for z in range(n):
					if MAT[z][j]==0:
						if [z,j] not in position:
							position.append([z,j])
					MAT[z][j]=1
