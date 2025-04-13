#https://www.naukri.com/code360/problems/jump-game_893178

from typing import List
from collections import deque


def minJumps(heights: List[int]) -> int:
    # write your code here
    dp=[0 for _ in range(len(heights))]
    for i in range(len(heights)):
        for j in range(i):
            if heights[j]+j>=i: #is it jumpable position?
                if dp[i]==0 and dp[j]!=-1: #if dp[i]==0 when minimum will always come 0...dp[j]!=-1 means reachable position
                    dp[i]=dp[j]+1
                else:
                    dp[i]=min(dp[i],dp[j]+1)
        #means the position is not the 1st and cant be reached
        if dp[i]==0 and i!=0:
            dp[i]=-1
    return dp[len(heights)-1]
