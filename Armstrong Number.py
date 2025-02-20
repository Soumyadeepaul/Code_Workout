#https://www.naukri.com/code360/problems/armstrong-number_1462443

from os import *
from sys import *
from collections import *
from math import *

def isArmstrong(num):
    # Write your code here.
    check_num=num
    result_num=0
    power=0
    while num:
        power+=1
        num//=10
    num=check_num
    while num:
        remainder=num%10
        num=num//10
        result_num+=(remainder**power)
    if check_num==result_num:
        return True
    return False
