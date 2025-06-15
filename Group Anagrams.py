#https://leetcode.com/problems/group-anagrams/description/?envType=study-plan-v2&envId=top-interview-150

from collections import Counter
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        result=[]
        store=[]
        for i in strs:
            sort=sorted(i)
            found=0
            for j in range(len(store)):
                if store[j]==sort:
                    result[j].append(i)
                    found=1
                    break
            if found==0:
                result.append([i])
                store.append(sort)
        return result
            
