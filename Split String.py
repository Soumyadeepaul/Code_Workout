#

from os import *
from sys import *
from collections import *
from math import *


def splitString(string: str) -> bool:
    # Write your code here.
    mid=len(string)//2

    string2=string[mid:]
    string=string[:mid]

    count=0
    count2=0

    for i in string:
        if i in 'aeiouAEIOU':
            count+=1

    for i in string2:
        if i in 'aeiouAEIOU':
            count2+=1
    
    return True if count==count2 else False
