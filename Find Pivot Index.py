#https://leetcode.com/problems/find-pivot-index/description/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        maxxi=sum(nums)
        starting=0
        pivot=0
        for i in range(0,len(nums)):
            pivot=i
            maxxi-=nums[i]
            if maxxi==starting:
                return pivot
            starting+=nums[pivot]
        return -1
