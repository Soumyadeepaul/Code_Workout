#https://www.naukri.com/code360/problems/find-numbers-containing-1-2-and-3_1214521

from os import *
from sys import *
from collections import *
from math import *

def containsNumber(n, arr):
    # Write your code here
    def stackSort(stack,num,result):
        if result:
            if result[-1]>num:
                val=result.pop()
                stackSort(stack,num,result)
                result.append(val)
            else:
                result.append(num)
        else:
            result.append(num)
        return
    result=[]
    for i in arr:
        num=i
        one=0
        two=0
        three=0
        while num:
            re=num%10
            num=num//10
            if re==1:
                one=1
            elif re==2:
                two=1
            elif re==3:
                three=1
            if one==1 and two==1 and three==1:
                stackSort(arr,i,result)
                break
    if not result:
        return [-1]
    return result
    
            
