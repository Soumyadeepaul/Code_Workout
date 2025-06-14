#https://leetcode.com/problems/maximum-subarray/description/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        

        window=[]
        summ=0
        result=0
        for i in nums:
            if summ+i<0:
                window=[]
                summ=0
            else:
                window.append(i)
                summ+=i
                result=max(result,summ)
        if result==0:
            result=max(nums)
        return result
