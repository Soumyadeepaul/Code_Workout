#https://leetcode.com/problems/house-robber/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums)<2:
            return nums[0]
        nums[1]=max(nums[0],nums[1])
        for i in range(2,len(nums)):
            nums[i]=max(nums[i-2]+nums[i],nums[i-1]) #DP
        return nums[-1]
