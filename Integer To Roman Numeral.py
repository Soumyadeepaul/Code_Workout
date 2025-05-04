#https://www.naukri.com/code360/problems/integer-to-roman-numeral_981307

from os import *
from sys import *
from collections import *
from math import *

def intToRoman(num):
    # Write your code here.
    symTable=[['I',1],['IV',4],['V',5],['IX',9],['X',10],
              ['XL',40],['L',50],['XC',90],['C',100],['CD',400],['D',500],['CM',900],['M',1000]]
    result=''
    for sym,val in reversed(symTable):
        if num//val:
            count=num//val
            result+=(sym*count)
            num=num%val
    return result
