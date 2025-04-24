#https://leetcode.com/problems/move-zeroes/description/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i=0
        j=i
        while i<len(nums):
            if nums[i]==0:
                if j<i:
                    j=i
                while j<len(nums) and nums[j]==0:
                    j+=1
                if j==len(nums):
                    j-=1
                nums[i],nums[j]=nums[j],nums[i]
            i+=1
                
        
