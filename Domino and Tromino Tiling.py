#https://leetcode.com/problems/domino-and-tromino-tiling/description/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def numTilings(self, n: int) -> int:
        dp=[0,1,2,5]
        i=4
        while i<=n:
            x=dp[i-3]
            dp.append((2*dp[i-1]+x)%(10**9 +7))
            i+=1
        return dp[n]

##########################
#LOGIC
#dp=[0,1,2,5]
#from next  2*dp[-1] + dp[i-3]
