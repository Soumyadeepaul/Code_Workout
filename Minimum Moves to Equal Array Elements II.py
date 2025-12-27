#https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/?envType=problem-list-v2&envId=sorting

class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        nums=sorted(nums)
        minn=nums[0]
        maxx=nums[len(nums)-1]
        count=0
        result=10**10+7
        for j in nums[int(len(nums)/2)-1:int(len(nums)/2)+1]:
            for i in nums:
                count+=abs(i-j)
            result=min(result,count)
            count=0
        return int(result)
