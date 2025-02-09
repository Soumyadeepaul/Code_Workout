#https://www.naukri.com/code360/problem-of-the-day/easy

from os import *
from sys import *
from collections import *
from math import *

def isReflectionEqual(s):
    # Write your code here.
    length=len(s)
    same=['A','H','I','M','O','T','U','V','W','X','Y']
    if length%2==1:
        if s[length//2] not in same:
            return 0
    for i in range(length//2):
        if s[i]!=s[length-i-1] or s[i] not in same:
            return 0
    return 1
