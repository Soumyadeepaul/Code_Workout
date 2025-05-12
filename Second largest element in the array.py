#https://www.naukri.com/code360/problems/second-largest-element-in-the-array_873375

from os import *
from sys import *
from collections import *
from math import *

from sys import stdin
import sys
import heapq
def findSecondLargest(sequenceOfNumbers):
    # Write your code here.
    for i in range(len(sequenceOfNumbers)):
        sequenceOfNumbers[i]=-sequenceOfNumbers[i]
    heapq.heapify(sequenceOfNumbers)
    val=heapq.heappop(sequenceOfNumbers)
    val2=heapq.heappop(sequenceOfNumbers)
    while val2==val:
        if sequenceOfNumbers:
            val2=heapq.heappop(sequenceOfNumbers)
        else:
            val2=1
            break
    return -val2















# Taking input using fast I/O.
def takeInput():
    n = int(input())

    sequenceOfNumbers = list(map(int, input().strip().split(" ")))

    return sequenceOfNumbers, n

# Main.
t = int(input())
while t:
    sequenceOfNumbers, n = takeInput()
    print(findSecondLargest(sequenceOfNumbers))
    t = t-1
