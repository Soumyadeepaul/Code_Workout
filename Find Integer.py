#https://www.naukri.com/code360/problem-of-the-day/easy

from sys import *
from collections import *
from math import *

def findInteger(n, k):
    # Write your code here
    # result=1
    # for i in range(k-1):
    #     result+=2
    #     if result>n:
    #         result=2
    # return result

    # 8 4  [1,3,5,7,2,4,6,8] ->7  #mid=4
    # 5 2  [1,3,5,2,4]-> 3   #mid=2
    # 7 4  [1,3,5,7,2,4,6]  #mid=3
    mid=n//2
    if n%2!=0: #if odd... mid with be +1
        mid+=1
    if k<=mid:#odd side    ex: 3=(1*2)+1....k is 1 indexing
        return ((k-1)<<1)+1

    else:  #even side
        k=k-mid
        return k<<1
