#https://leetcode.com/problems/remove-duplicates-from-sorted-array/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        count=1
        prev=nums[0]
        idx=1
        for i in range(1,len(nums)):
            if nums[i]==prev:
                pass
            else:
                prev=nums[i]
                nums[idx]=nums[i]
                count+=1
                idx+=1
        return count
            
