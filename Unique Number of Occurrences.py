#https://leetcode.com/problems/unique-number-of-occurrences/description/?envType=study-plan-v2&envId=leetcode-75
class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        hashmap={}
        for i in arr:
            if i not in hashmap:
                hashmap[i]=1
            else:
                hashmap[i]+=1
        duplicate=set()
        for i in hashmap.values():
            if i in duplicate:
                return False
            else:
                duplicate.add(i)
        return True
        
