#https://leetcode.com/problems/n-th-tribonacci-number/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def tribonacci(self, n: int) -> int:
        dp=[0,1,1]
        for i in range(3,n+1):
            dp.append(dp[i-3]+dp[i-2]+dp[i-1])
        return dp[n]
        
