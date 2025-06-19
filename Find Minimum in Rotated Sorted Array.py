#https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def findMin(self, nums: List[int]) -> int:
        
        #FIND PIVOT

        start=0
        end=len(nums)-1
        mid=0
        result=0
        while start<=end:
            mid=start+(end-start)//2
            result=nums[mid]
            if mid-1>-1 and mid+1<len(nums):
                if nums[mid]<nums[mid-1] and nums[mid]<nums[mid+1]:
                    return nums[mid]
            if nums[mid]>nums[end]: #MOVE TO LEFT SIDE
                start=mid+1
            else:
                end=mid-1
        return result
