class Solution:
    def countBits(self, n: int) -> List[int]:
        # result=[]
        # i=0
        # while i<n+1:
        #     num=i
        #     count=0
        #     while num:
        #         if num%2:
        #             count+=1
        #         num=num//2
        #     result.append(count)
        #     if i!=n:
        #         result.append(count+1)
        #     i+=2
        # return result
        ##############################
        #DP
        dp=[0]*(n+1)
        for i in range(1,n+1):
            dp[i]=dp[i>>1]+(i&1)
        return dp
        
