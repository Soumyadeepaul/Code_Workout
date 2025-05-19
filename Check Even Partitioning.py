#

from os import *
from sys import *
from collections import *
from math import *

def checkEvenPartitioning(n):
    # Write your code here
    # Return a Boolean
    if n==2: #Except 2 every even number can be partition into evens
        return False
    if n&1:
        return False
    return True


