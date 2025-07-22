#https://leetcode.com/problems/maximum-erasure-value/description/?envType=daily-question&envId=2025-07-22

class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        maxi=-10**9+7
        i=0
        j=0
        window=set()
        while i<=j and j<len(nums):
            if nums[j] not in window:
                window.add(nums[j])
                j+=1
            else:
                maxi=max(maxi,sum(nums[i:j]))
                while nums[i]!=nums[j]:
                    window.remove(nums[i])
                    i+=1
                window.remove(nums[i])
                i+=1
        maxi=max(maxi,sum(nums[i:j]))
        return maxi
                
                
