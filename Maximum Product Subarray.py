#https://leetcode.com/problems/maximum-product-subarray/description/?envType=problem-list-v2&envId=dynamic-programming

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        result=-10^9+7
        i=0   #from left side
        j=len(nums)-1 #from right side
        left=1 #prefix Mul
        right=1 #suffix Mul
        while i<len(nums):
            left*=nums[i]
            right*=nums[j]
            result=max(result,left,right)
            #if any of the Mul gets 0, set as 1, like kadane's algo
            if left==0:
                left=1
            if right==0:
                right=1
            i+=1
            j-=1
        return result
        
