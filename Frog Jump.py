#https://www.naukri.com/code360/problems/frog-jump_3621012

from os import *
from sys import *
from collections import *
from math import *

from typing import *

  
def frogJump(n: int, heights: List[int]) -> int:

    # Write your code here.
    def jump(index,heights,dp):
        if dp[index]!=-1:
            return dp[index]
        if index==0:
            return 0
        #when 1 step is taken back
        #jump() used for enegry needed to reach the previous step
        # + the enegry used for reaching that step
        by1=jump(index-1,heights,dp)+abs(heights[index]-heights[index-1])
        #when 2 step is taken back
        by2=999999
        if index>1:
            by2=jump(index-2,heights,dp)+abs(heights[index]-heights[index-2])
        #store the minimum in the step
        dp[index]=min(by1,by2)
        return dp[index]
    #dp is used for maintaining least energy used to reach the step
    dp=[-1 for _ in range(n)]
    val=jump(n-1,heights,dp)
    return val
