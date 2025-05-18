#https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        
        prev=nums[0]
        count=1
        idx=1
        sameCount=1
        for i in range(1,len(nums)):
            if prev==nums[i] and sameCount==2:
                pass
            elif prev==nums[i] and sameCount==1:
                nums[idx]=nums[i]
                idx+=1
                sameCount=2
                count+=1
            else:
                prev=nums[i]
                nums[idx]=nums[i]
                count+=1
                idx+=1
                sameCount=1
        return count
