#

from os import *
from sys import *
from collections import *
from math import *

def findNonRepeating(str):
    # Write your code here
    # Return a single character
    hashmap=Counter(str)
    for i in hashmap:
        if hashmap[i]==1:
            return i
    return '#'
