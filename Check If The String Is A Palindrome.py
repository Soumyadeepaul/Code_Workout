#https://www.naukri.com/code360/problems/check-if-the-string-is-a-palindrome_1062633

from os import *
from sys import *
from collections import *
from math import *

def checkPalindrome(s):
    # Write your code here
	# Return a boolean
	st=""
	for i in s:
		if (ord(i)>=65 and ord(i)<=65+26) or (ord(i)>=97 and ord(i)<=97+26) or (ord(i)>=48 and ord(i)<=48+10):
			st+=i.upper()
	from_last=len(st)
	#print(st)
	for i in range(len(st)//2):
		from_last-=1
		if st[i]!=st[from_last]:
			return False
	return True
