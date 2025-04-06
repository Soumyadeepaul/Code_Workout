#

from os import *
from sys import *
from collections import *
from math import *

def oneSegment(str):
    # Write your code here.
    count=0
    seq=0
    for i in str:
        if i=='1':
            seq+=1
        elif seq!=0:
            count+=1
            seq=0
        if count>1:
            return 0
    if seq!=0 and str[-1]=='1':
        count+=1
    if count>1:
        return 0
    return 1
