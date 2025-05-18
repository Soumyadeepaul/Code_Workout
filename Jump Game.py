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

###################################################################################
#https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        idxx=[10**7 for _ in range(len(nums))] #from which index it is coming from
        jump=idxx.copy() #How many jump to take
        jump[0]=0
        checked=0
        for i in range(0,len(nums)):
            val=nums[i]
            jumpVal=jump[i]+1
            for j in range(checked,i+1+val):
                if j>=len(nums):
                    break
                idxx[j]=min(idxx[j],i)
                jump[j]=min(jump[j],jumpVal)
            checked=i+1+val
        print(jump,idxx)
        if jump[-1]==10**7:
            return False
        return True
    #LOGIC
    #     0 1 2 3 4 5
    #    [3,2,1,1,0,4]
    #idx=[0,0,0,1,3,4]
    #jum=[0,1,1,2,2,None]
