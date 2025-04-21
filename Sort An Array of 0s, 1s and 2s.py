#https://www.naukri.com/code360/problems/sort-an-array-of-0s-1s-and-2s_892977

from os import *
from sys import *
from collections import *
from math import *

def sortArray(arr, n):

	# Write your code here

	#3 pointer logic, i for 0, curr for 1, j for 2
	curr=0
	i=0
	j=n-1
	while curr<j:
		while arr[curr]==1 and n-1>curr:
			curr+=1
		#if curr=0, take it to front
		if arr[curr]==0:
			arr[i],arr[curr]=arr[curr],arr[i]
			i+=1
			curr+=1
		while arr[j]==2 and j>-1:
			j-=1
		#if curr=2, take it to back
		if arr[curr]==2 and j>curr:
			arr[j],arr[curr]=arr[curr],arr[j]
	return arr
