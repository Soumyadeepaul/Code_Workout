#

from os import *
from sys import *
from collections import *
from math import *

def toggleKBits(n, k):

    # Write your code here.
    # This function returns updated number after toggling the given K bits.
    
    result=0
    power=1
    while n:
        rem=n%2
        if k!=0:
            if rem:
                rem=0
            else:
                rem=1
            k-=1
        result+=rem*power
        power=power<<1
        n=n//2
    while k:
        result+=1*power
        power=power<<1
        k-=1
    return result
