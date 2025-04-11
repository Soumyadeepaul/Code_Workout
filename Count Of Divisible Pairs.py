#https://www.naukri.com/code360/problems/sum-of-numbers_975486


from os import *
from sys import *
from collections import *
from math import *

def countOfDivisiblePairs(n, m):
    # Write your code here.
    count=0
    for i in range(1,n+1):
        for j in range(1,m+1):
            #print(i,j)
            if (i+j)%5==0:
                count+=1
    return count
