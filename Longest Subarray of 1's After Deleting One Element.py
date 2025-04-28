#https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        window=[]
        maxi=0
        i=0
        count=0
        while i<len(nums):
            if nums[i]==1:
                window.append(1)
            else:
                if count==0:
                    count+=1
                    window.append(0)
                else:
                    while window and window[0]!=0:
                        window.pop(0)
                    if window:
                        window.pop(0)
                    window.append(0)
            maxi=max(maxi,len(window))
            i+=1
        if count==1:
            maxi-=1
        if len(nums)==maxi:
            maxi-=1
        return maxi

        
