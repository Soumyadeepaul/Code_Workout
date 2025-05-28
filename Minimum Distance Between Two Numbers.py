#
from sys import *
from collections import *
from math import *

def minimumDistance(arr, n, x, y):
	# Write your code here
    # Return an integer
    xFound=0
    yFound=0
    xPosition=0
    yPosition=0
    result=10**9+7
    for i in range(n):
        if arr[i]==x:
            xFound=1
            xPosition=i
        elif arr[i]==y:
            yPosition=i
            yFound=1
        if xFound and yFound:
            result=min(result,abs(yPosition-xPosition))
    return result if result!=10**9+7 else -1
