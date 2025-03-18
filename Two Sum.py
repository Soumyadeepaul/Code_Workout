#https://leetcode.com/problems/two-sum/description/


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        #hashing
        dic={}
        for i in range(len(nums)):
            first=nums[i]
            second=target-first
            if second in dic.keys():
                return [i,dic[second]]
            dic[first]=i
