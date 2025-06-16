#https://leetcode.com/problems/contains-duplicate-ii/?envType=problem-list-v2&envId=hash-table

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        hashmap={}
        for i in range(len(nums)):
            if nums[i] not in hashmap:
                hashmap[nums[i]]=[1,[i]]
            else:
                hashmap[nums[i]][0]+=1
                hashmap[nums[i]][1].append(i)
        for i in hashmap:
            if hashmap[i][0]>1:
                for a in hashmap[i][1]:
                    for b in hashmap[i][1]:
                        if a==b:
                            pass
                        elif abs(a-b)<=k:
                            return True
        return False
