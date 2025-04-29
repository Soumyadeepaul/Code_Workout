#https://leetcode.com/problems/find-the-difference-of-two-arrays/description/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        i=0
        nums1,nums2=list(set(nums1)),list(set(nums2))
        while i<len(nums1):
            j=0
            popped=0
            val=nums1[i]
            while j<len(nums2):
                if popped==1 and val==nums2[j]:
                    nums2.pop(j)
                elif val==nums2[j]:
                    nums1.pop(i)
                    nums2.pop(j)
                    popped=1
                else:
                    j+=1
            if popped==0:
                i+=1
        return [nums1,nums2]
