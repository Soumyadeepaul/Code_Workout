#https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums:
            return [-1,-1]
        start=0
        end=len(nums)-1
        left=-1
        while start<=end:
            mid=start+(end-start)//2

            if nums[mid]<target:
                start=mid+1
            elif nums[mid]>target:
                end=mid-1
            else:
                left=mid
                end=mid-1

        start=left
        end=len(nums)-1
        right=-1
        while start<=end:
            mid=start+(end-start)//2
            if nums[mid]>target:
                end=mid-1
            elif nums[mid]==target:
                right=mid
                start=mid+1
            else:
                break
        
        return [left,right]
        
        
