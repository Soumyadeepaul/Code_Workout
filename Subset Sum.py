#https://www.naukri.com/code360/problems/subset-sum_3843086

from sys import *
from collections import *
from math import *

from typing import List

def subsetSum(num: List[int]) -> List[int]:
    # Write your code here.

    def subsetSumFun(num,subset,ans,i):
        if i==len(num):
            val=sum(subset)
            ans.append(val)
            return
        #Recursion
        subset.append(num[i]) #choosing the element
        subsetSumFun(num,subset,ans,i+1)

        #Backtracking
        subset.pop() #not choosing the element
        subsetSumFun(num,subset,ans,i+1)
        
    ans=[]
    subset=[]
    subsetSumFun(num,subset,ans,0)
    return sorted(ans)
