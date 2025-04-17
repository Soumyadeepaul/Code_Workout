#https://leetcode.com/problems/unique-paths-ii/

class Solution:
    def uniquePathsWithObstacles(self, mat: List[List[int]]) -> int:
        n=len(mat)
        m=len(mat[0])
        dp=[0 for _ in range(m+1)]
        dp[m-1]=1
        while n!=0:
            for i in range(m-1,-1,-1):
                if mat[n-1][i]==1: #if it is obstacle, the  -1, means it cannot be reached or used
                    dp[i]=-1
                else:
                    if dp[i+1]==-1 or dp[i]==-1: #if any one of bottom/self or right is obstacle, then the other one comes
                        dp[i]=max(dp[i+1],dp[i])
                    else:
                        dp[i]=dp[i]+dp[i+1]  #unique path
            n-=1
        if dp[0]==-1: #if -1, therefore can't be reached
            return 0
        return dp[0]
