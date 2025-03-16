#https://www.naukri.com/code360/problem-of-the-day/easy

from os import *
from sys import *
from collections import *
from math import *

def minCashFlow(money, n):

    # Write your code here.
    debt=[sum(i) for i in money]
    inflow=[0 for _ in range(n)]
    for i in money:
        for j in range(n):
            if i[j]!=0:
                inflow[j]+=i[j]
    ans=0
    for i in range(n):
        if inflow[i]-debt[i]<0:
            ans+=abs(inflow[i]-debt[i])
    return ans
