#

from os import *
from sys import *
from collections import *
from math import *




#Write your countBits function here.
def countBits(n):
    count=0
    while n:
        if n%2==1:
            count+=1
        n//=2
    return count




        
n = int(input())
print(countBits(n))

