#https://www.naukri.com/code360/problem-of-the-day/easy?leftPanelTabValue=PROBLEM

from sys import *
from collections import *
from math import *

def countColumns(strings):
    # Write your code here.
    i=0
    count=0
    while i<len(strings[0]):
        sort=1
        for j in range(len(strings)-1):
            if strings[j][i]>strings[j+1][i]:
                sort=0
                break
        if sort==0:
            count+=1
        i+=1
    return count
