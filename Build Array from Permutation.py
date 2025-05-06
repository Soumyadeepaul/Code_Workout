#https://leetcode.com/problems/build-array-from-permutation/description/?envType=daily-question&envId=2025-05-06

class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        result=[]
        for i in nums:
            result.append(nums[i])
        return result
        
