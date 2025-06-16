#https://leetcode.com/problems/longest-consecutive-sequence/description/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # if not nums:
        #     return 0
        # maxi=max(nums)
        # mini=min(nums)
        # arr=[]
        # for i in range(mini,maxi+1):
        #     if i==0:
        #         arr.append(1)
        #     else:
        #         arr.append(i)
        # for i in nums:
        #     arr[i-mini]=0
        # longest=0
        # longCount=0
        # for i in arr:
        #     if i==0:
        #         longCount+=1
        #     else:
        #         longest=max(longest,longCount)
        #         longCount=0
        # longest=max(longest,longCount)
        # return longest

        numSet=set(nums)
        longest=0
        for i in nums:
            if i-1 not in numSet: #CHECK EVERY element starting element or not.... if 100, check 99 is present or not, if not present... check the longest length with 100...
            #remove 101, 102... as for becomeing longest with 101... 100 must be present
                length=1
                while i+length in numSet:
                    numSet.remove(i+length)
                    length+=1
                    
                longest=max(longest,length)
        return longest
