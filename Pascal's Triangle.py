#https://www.naukri.com/code360/problems/pascal-s-triangle_1089580

from collections import *
from math import *

def printPascal(n:int):
    # Write your code here.
    # Return a list of lists.
    if n==1:
        return [[1]]
    result=[[1]]
    n-=1
    length=2
    while n!=0:
        n-=1
        previous=result[-1]
        pos=1
        new=[1,1]
        if length!=2:
            while pos!=length-1:
                new.insert(pos,previous[pos-1]+previous[pos])
                pos+=1
        result.append(new)
        length+=1
    return result
