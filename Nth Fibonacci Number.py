#https://www.naukri.com/code360/problems/nth-fibonacci-number_74156

from math import *
from collections import *
from sys import *
from os import *

## Read input as specified in the question.
## Print output as specified in the question.
n=int(input())
first=0
second=1
while n!=1:
    second,first=first+second,second
    n-=1
print(second)
