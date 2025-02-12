#https://www.naukri.com/code360/problems/sum-of-two-arrays_893186


#[9,9] + [9,9,9]
#step 1 :   [0,9,9],[9,9,9]
#step 2:  n-1->0   if>10 calculate carry
#step 3: carry at the MSB, insert
from os import *
from sys import *
from collections import *
from math import *

def addition(a,n,b):
    carry=0
    for i in range(n-1,-1,-1):
        summ=a[i]+b[i]+carry
        b[i]=summ%10
        carry=summ//10
    if carry!=0:
        b.insert(0,carry)
    return b


def findArraySum(a, n, b, m):
    # Write your code here.
    
    if m>n:
        for _ in range(m-n):
            a.insert(0,0)
    else:
        for _ in range(n-m):
            b.insert(0,0)
    return addition(a,max(n,m),b)
