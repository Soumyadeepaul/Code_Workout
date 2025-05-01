#https://leetcode.com/problems/min-cost-climbing-stairs/description/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp=[0]*(len(cost)+1)
        cost.append(0)
        for i in range(2,len(cost)):
            dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2])
        return dp[-1]
