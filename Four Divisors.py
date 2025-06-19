#

from os import *
from sys import *
from collections import *
from math import *

def sumFourDivisors(arr, n):
    # Write your code here.
    result=0

    for i in arr:
        divisors=2
        store=[1,i]
        for j in range(2,(i//2)+1):
            if i%j==0:
                store.append(j)
                divisors+=1
            if divisors>4:
                break
        if divisors==4:
            result+=sum(store)
    return result
