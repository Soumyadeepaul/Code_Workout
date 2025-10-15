//https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/description/?envType=daily-question&envId=2025-10-15


class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        k=0
        currSize=1
        prevSize=0
        for i in range(1,len(nums)):
            if nums[i-1]<nums[i]:
                currSize+=1
            else:
                prevSize=currSize
                currSize=1
            k=max(k,currSize//2)
            k=max(k,min(prevSize,currSize))
        return k
       
