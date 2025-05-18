#https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        
        # def quick(nums,low,high):
        #     pivot=nums[high]
        #     i=low-1
        #     j=low
        #     while j<high:
        #         if nums[j]<pivot:
        #             i+=1
        #             nums[i],nums[j]=nums[j],nums[i]
        #         j+=1
        #     nums[i+1],nums[high]=nums[high],nums[i+1]
        #     return i+1
        # def quickSort(nums,left,right):
        #     if left<right:
        #         p=quick(nums,left,right)
        #         quickSort(nums,left,p-1)
        #         quickSort(nums,p+1,right)


        
        #quickSort(nums,0,len(nums)-1)

        nums.sort()
        return nums[len(nums)//2]
