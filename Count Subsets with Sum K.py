#https://www.naukri.com/code360/problems/number-of-subsets_3952532
############################
TLE - DP NEEDED
########################
from typing import List

def findWays(arr: List[int], k: int) -> int:
    # Write your code here.

    def subsetFun(arr,i,k,count,summation):
        #no need to maintain subset
        if i==len(arr):
            if summation==k:
                count+=1
            return count
        summation+=arr[i]
        #if adding the value excide the target... no meaning to preceed with it.
        if summation<=k:
            count=subsetFun(arr,i+1,k,count,summation)
        summation-=arr[i]
        count=subsetFun(arr,i+1,k,count,summation)
        return count
    count=0
    return subsetFun(arr,0,k,count,0)
