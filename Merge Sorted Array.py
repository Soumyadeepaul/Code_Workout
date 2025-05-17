#https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

from heapq import heappush,heappop,heapify
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        heapify(nums2)
        idx=0
        val2=0
        while nums2 and idx<m+n:
            if val2==0:
                val2=nums2[0]
            if nums1[idx]==0 and idx>=m:
                heappop(nums2)
                nums1[idx]=val2
                val2=0
            elif nums1[idx]>val2:
                heappop(nums2)
                heappush(nums2,nums1[idx])
                nums1[idx]=val2
                val2=0
            idx+=1
        
                
        

            
        
        
