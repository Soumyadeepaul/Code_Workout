#https://www.naukri.com/code360/problems/merge-k-sorted-arrays_975379

from sys import *
from collections import *
from math import *

def mergeKSortedArrays(kArrays, k:int):
	# Write your code here.
	# kArrays is a list of 'k' lists.
	# Return a list.
	def sort(arr1,arr2):
		i=j=0
		extra_space=[]
		while i<len(arr1) and j<len(arr2):
			if arr1[i]<arr2[j]:
				extra_space.append(arr1[i])
				i+=1
			else:
				extra_space.append(arr2[j])
				j+=1
		while i<len(arr1):
			extra_space.append(arr1[i])
			i+=1
		while j<len(arr2):
			extra_space.append(arr2[j])
			j+=1
		return extra_space



	sorted_yet=kArrays[0]
	for i in range(1,k):
		sorted_yet=sort(sorted_yet,kArrays[i])
	return sorted_yet

