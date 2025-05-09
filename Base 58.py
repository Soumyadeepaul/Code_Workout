#

from sys import *
from collections import *
from math import *

def encodeBase58(n):
    # Write your code here
    if n==0:
        return '1'
    nums='123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz'
    string=[]
    result=''
    while n!=0:
        rem=n%58
        n=n//58
        string.insert(0,rem)
    for i in string:
        result+=nums[i]
    return result
