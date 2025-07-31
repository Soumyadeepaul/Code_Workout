#https://leetcode.com/problems/number-of-islands/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        
        def bfs(grid,i,j):
            queue=[[i,j]]
            while queue:
                i,j=queue.pop(0)
                if i-1>-1 and grid[i-1][j]=='1':
                    grid[i-1][j]='0'
                    queue.append([i-1,j])
                if i+1<len(grid) and grid[i+1][j]=='1':
                    grid[i+1][j]='0'
                    queue.append([i+1,j])
                if j-1>-1 and grid[i][j-1]=='1':
                    grid[i][j-1]='0'
                    queue.append([i,j-1])
                if j+1<len(grid[0]) and grid[i][j+1]=='1':
                    grid[i][j+1]='0'
                    queue.append([i,j+1])
        count=0
        for x in range(len(grid)):
            for y in range(len(grid[0])):
                if grid[x][y]=='1':
                    count+=1
                    bfs(grid,x,y)
        return count
