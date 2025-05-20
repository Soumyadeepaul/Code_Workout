#https://leetcode.com/problems/h-index/description/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n=len(citations)
        dp=[0 for _ in range(n+1)]
        for i in citations:
            if i>n:
                dp[n]+=1
            else:
                dp[i]+=1
        summ=0
        for i in range(len(dp)-1,-1,-1):
            summ+=dp[i]
            if summ>=i:
                return i
        return 0
