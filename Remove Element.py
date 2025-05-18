#https://leetcode.com/problems/remove-element/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k=0
        i=0
        j=len(nums)-1
        #TWO POINTER
        while i<=j:
            if nums[i]!=val:
                k+=1
                i+=1
            else:
                nums[j],nums[i]=nums[i],nums[j]
                j-=1
        return k
            
