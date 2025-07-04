#

from os import *
from sys import *
from collections import *
from math import *

def calculateScore(matchResult, n):
    # Write your code here.
    track=[]
    for i in matchResult:
        if i not in '+DC':
            track.append(int(i))
        elif i=='D':
            track.append(track[-1]*2)
        elif i=='C':
            track.pop()
        else:
            track.append(track[-1]+track[-2])
    return sum(track)
