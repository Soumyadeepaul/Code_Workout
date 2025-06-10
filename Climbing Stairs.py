#https://leetcode.com/problems/climbing-stairs/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def climbStairs(self, n: int) -> int:
        
        dp=[1,2]
        for i in range(2,n):
            dp.append(dp[i-1]+dp[i-2])
        return dp[n-1]
