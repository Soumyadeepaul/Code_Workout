#https://www.naukri.com/code360/problems/different-bits-sum-pairwise_1082152

from os import *
from sys import *
from collections import *
from math import *

def differentBitsSumPairwise(arr, n):
    # Write your code here
    # Return an integer denoting the total sum f(x,y).
    
    def summ(x,y):
        x=bin(x)[2:]
        y=bin(y)[2:]
        x_len=len(x)
        y_len=len(y)
        # if x_len>y_len:
        #     extra=x_len-y_len
        #     while extra:
        #         y='0'+y
        #         extra-=1
        # elif x_len<y_len:
        #     extra=y_len-x_len
        #     while extra:
        #         x='0'+x
        #         extra-=1
        # count=0
        # for i in range(len(x)):
        #     if x[i]!=y[i]:
        #         count+=1
        # return count

        if x_len<y_len:
            x_len,y_len=y_len,x_len
            x,y=y,x
        #start with small y_len
        count=0
        for i in range(y_len):
            if x[x_len-y_len+i]!=y[i]:
                count+=1
        for i in range(x_len-y_len):
            if int(x[i]):
                count+=1
        return count


    count=0
    for i in range(len(arr)-1):
        for j in range(i+1,len(arr)):
            if arr[i]!=arr[j]:
                count+=summ(arr[i],arr[j])
    return count<<1


