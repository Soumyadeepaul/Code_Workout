#https://leetcode.com/problems/minimum-path-sum/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        dp=[[0 for _ in range(len(grid[0])+1)]for _ in range(len(grid)+1)]
        for i in range(len(grid)-1,-1,-1):
            for j in range(len(grid[0])-1,-1,-1):
                if i+1==len(grid) and j+1==len(grid[0]):
                    dp[i][j]=grid[i][j]
                elif i+1==len(grid) and j+1!=len(grid[0]):
                    dp[i][j]=dp[i][j+1]+grid[i][j]
                elif i+1!=len(grid) and j+1==len(grid[0]):
                    dp[i][j]=dp[i+1][j]+grid[i][j]
                else:
                    dp[i][j]=min(dp[i+1][j],dp[i][j+1])+grid[i][j]
        

        return dp[0][0]
