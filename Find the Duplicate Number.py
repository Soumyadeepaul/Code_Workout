#https://leetcode.com/problems/find-the-duplicate-number/

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        hashmap={}
        for i in nums:
            if i not in hashmap:
                hashmap[i]=1
            else:
                return i
