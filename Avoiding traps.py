#https://www.naukri.com/code360/problem-of-the-day/moderate

from os import *
from sys import *
from collections import *
from math import *

def avoidTraps(obstacles, n):
    # Write your code here.
    maxx=max(obstacles)+10
    for i in range(1,maxx):
        if i in obstacles:
            pass
        else:
            ith=i
            while True:
                jump=i
                if jump in obstacles:
                    break
                elif jump>maxx:
                    return ith 
                i+=ith

def takeInput():
    n = int(input())

    obstacles = list(map(int, input().strip().split(" ")))

    return obstacles, n

t = int(input())
while t:
    obstacles, n = takeInput()
    print(avoidTraps(obstacles, n))
    t = t-1
