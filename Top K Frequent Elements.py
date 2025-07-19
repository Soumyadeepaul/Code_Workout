#https://leetcode.com/problems/top-k-frequent-elements/description/?envType=problem-list-v2&envId=heap-priority-queue

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        hashmap={}
        for i in nums:
            if i not in hashmap:
                hashmap[i]=1
            else:
                hashmap[i]+=1
        result=[]
        maxi=-10**9+7
        element=0
        while len(result)!=k:
            for i in hashmap:
                if hashmap[i]>maxi:
                    maxi=hashmap[i]
                    element=i
            result.append(element)
            hashmap[element]=-10**9+7
            maxi=-10**9+7
        return result
            


        
