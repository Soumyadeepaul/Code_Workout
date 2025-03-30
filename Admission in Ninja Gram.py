from os import *
from sys import *
from collections import *
from math import *

def ninjaGram(str):

    # Write your Code Here.
    # Return a boolean variable 'True' or 'False' denoting the answer
    element=set()
    for i in str:
        element.add(i.lower())
    if len(element)==26:
        return True
    return False
