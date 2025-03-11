#https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        # i=len(nums)-1
        # space_count=0
        # while i>0:
        #     if nums[i]==nums[i-1]:
        #         nums[i]='_'
        #         space_count+=1
        #     if nums[i]=='_':
        #         for j in range(i+1,len(nums)):
        #             if nums[j]!='_':
        #                 nums[j-1]=nums[j]
        #                 nums[j]='_'
        #             else:
        #                 break
        #     i-=1
        # return len(nums)-space_count

        i=0
        present=1
        count=-1
        new=nums[0]
        while i<len(nums):
            val=nums[i]
            #when 2 adj. values are different, put it into the consequetive location
            if new!=val:
                nums[present]=val
                new=val
                present+=1
            else:
                count+=1
            i+=1
        return len(nums)-count


        
