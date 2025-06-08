#

from sys import *
from collections import *
from math import *

def findFirstRepeatingDigit(digitPattern):

    # Write your code here.
    # This function returns the first repeating digit integer value.
    hashmap={}
    for i in digitPattern:
        if i not in hashmap:
            hashmap[i]=1
        else:
            return i
    return -1
