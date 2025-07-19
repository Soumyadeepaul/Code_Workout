#https://leetcode.com/contest/biweekly-contest-161/problems/count-islands-with-total-value-divisible-by-k/description/


class Solution:
    def countIslands(self, grid: List[List[int]], k: int) -> int:
        def bfs(grid,i,j,count):
            queue=[[i,j]]
            summ=grid[i][j]
            grid[i][j]=0
            row=len(grid)
            col=len(grid[0])
            while queue:
                i,j=queue.pop(0)
                if i+1<row and grid[i+1][j]!=0:
                    summ+=grid[i+1][j]
                    grid[i+1][j]=0
                    queue.append([i+1,j])
                if i-1>-1 and grid[i-1][j]!=0:
                    summ+=grid[i-1][j]
                    grid[i-1][j]=0
                    queue.append([i-1,j])

                if j+1<col and grid[i][j+1]!=0:
                    summ+=grid[i][j+1]
                    grid[i][j+1]=0
                    queue.append([i,j+1])
                if j-1>-1 and grid[i][j-1]!=0:
                    summ+=grid[i][j-1]
                    grid[i][j-1]=0
                    queue.append([i,j-1])
            if summ%k==0:
                count+=1
            return [grid,count]

        count=0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]!=0:
                    grid,count=bfs(grid,i,j,count)
        return count©leetcode
