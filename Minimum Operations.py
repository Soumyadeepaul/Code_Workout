#https://www.naukri.com/code360/problems/day-10-minimum-operations_762937

from os import *
from sys import *
from collections import *
from math import *

def minimumOperation(arr, n):
    # Write your code here.
    count=Counter(arr)
    count=count.most_common()
    op=0
    for i in range(1,len(count)):
        op+=count[i][1]
    return op

# Main.
t = int(input())
while t > 0:
    n = int(input())
    arr = [int(i) for i in input().split()]
    print(minimumOperation(arr,n))
    t -= 1
