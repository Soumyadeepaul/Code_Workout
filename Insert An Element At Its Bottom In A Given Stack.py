#
from os import *
from sys import *
from collections import *
from math import *

def pushAtBottom(myStack: deque, x: int):
	# Write your code here.
	myStack.appendleft(x)
	return myStack
