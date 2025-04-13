#https://www.naukri.com/code360/problems/convert-string_1062635

from os import *
from sys import *
from collections import *
from math import *

def convertString(str1):
    # Write your code here
    str1=list(str1)
    for i in range(len(str1)):
        if i==0:
            if ord(str1[i])>=65 and ord(str1[i])<=65+26:
                pass
            else:
                str1[i]=chr(ord(str1[i])-(97-65))
        elif str1[i-1]==' ':
            if ord(str1[i])>=65 and ord(str1[i])<=65+26:
                pass
            else:
                str1[i]=chr(ord(str1[i])-(97-65))
    return ''.join(str1)
