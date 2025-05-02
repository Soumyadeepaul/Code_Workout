#https://www.naukri.com/code360/problems/calculate-square-of-a-number_1112623

from os import *
from sys import *
from collections import *
from math import *

def calculateSquare(n):
    #    Write your code here
    if n<0:
        n=-n
    num=n
    power=[]
    i=0
    while n:
        rem=n%2
        n=n//2
        if rem==1:
            power.append(i)
        i+=1
    result=0
    while power:
        p=power.pop()
        result+=num<<p
    return result

    ####################################
    #LOGIC
    # 9 -> 1001
    #power->[3,0] and 1001 means 2^3+2^0
    #9<<3 -> means 9*(2^3)  + 9<<0 -> means 9*(2^0)

    #LOGIC LIKE POW(n,m) execept * we use num<<power
