#https://leetcode.com/problems/jump-game-ii/description/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def jump(self, nums: List[int]) -> int:
        dp=[10**9+7 for _ in nums]
        dp[0]=0
        reached=0
        for i in range(len(nums)):
            for j in range(reached+1,i+nums[i]+1):
                if j<len(nums):
                    dp[j]=min(dp[j],dp[i]+1)
                    reached=j
                else:
                    break
        
        return dp[-1]
