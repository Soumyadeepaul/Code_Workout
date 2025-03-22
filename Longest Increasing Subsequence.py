#https://leetcode.com/problems/longest-increasing-subsequence/description/

class Solution:
    def lengthOfLIS(self, arr: List[int]) -> int:
        n=len(arr)
        if n==1:
            return 1
        memo=[1 for _ in range(n)]
        i=1
        maxLength=1
        # [2,3,1,5,4]
        #  j i
        # [1,2,1,1,1] memo

        # [2,3,1,5,4]
        #    j   i
        # [1,2,1,3,1] memo
        while i<n:
            j=i-1
            while j>-1:
                # break because  the length before that j position is smaller then memo[i]
                # then how we will get greater value then memo[i]
                if memo[i]>j+1:
                    break
                if arr[j]<arr[i]:
                    new_len=memo[j]+1
                    if new_len>memo[i]:
                        memo[i]=new_len
                        #finding maximum of the arrar
                        if maxLength<new_len:
                            maxLength=new_len
                j-=1
            i+=1
        return maxLength
