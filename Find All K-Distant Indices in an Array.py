#https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/?envType=daily-question&envId=2025-06-24
class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        findKey=set()
        for i in range(len(nums)):
            if nums[i]==key:
                findKey.add(i)
        result=[]
        for i in range(len(nums)):
            for j in findKey:
                if abs(i-j)<=k:
                    result.append(i)
                    break
        return result
