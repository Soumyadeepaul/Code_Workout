#https://www.naukri.com/code360/problems/compress-the-string_18445721

from os import *
from sys import *
from collections import *
from math import *


def compressTheString(head):

	# Write your code here.
	i=0
	val=head[0]
	starting=0
	count=0
	while i<len(head):
		if val==head[i]:
			count+=1
			i+=1
		else:
			val=head[i]
			if count>1:
				head=head[:starting+1]+str(count)+head[i:]
				starting+=len(str(count))+1
			else:
				starting+=1
			count=0
			i=starting
	if count!=1:
		head=head[:starting+1]+str(count)
	return head
