#

from os import *
from sys import *
from collections import *
from math import *

def decrypt(message, operations):
    # Write your code here.
    agg=0
    for i,j in operations:
        if i==-1:
            agg-=j
        else:
            agg+=j
    if agg>=0:
        while agg!=0:
            message=message[-1]+message[:-1]
            agg-=1
    else:
        while agg!=0:
            message=message[1:]+message[0]
            agg+=1
    return message
