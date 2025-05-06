#https://leetcode.com/problems/rotting-oranges/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        positionI=-1
        positionJ=-1
        maxii=-1
        queue=[] #TO STORE THE POSITION
        #FIND ALL 2 IN THE GRID
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]==2:
                    positionI=i
                    positionJ=j
                    queue.append([positionI, positionJ])
                    grid[i][j]=5 #let level 0 be 5
        ########################################
        #no 2 found
        if positionI==-1 and positionJ==-1:
            for i in grid:
                if 1 in i:
                    return -1
            return 0
        ####################################
        else:
            #BFS
            #let level 0 be 5
            maxii=5
            while queue:
                val=queue.pop(0)
                i,j=val[0],val[1]

                if i-1>-1 and grid[i-1][j]==1:
                    grid[i-1][j]=grid[i][j]+1 #MARKING THE LEVEL +1
                    queue.append([i-1,j]) #inserting in queue
                    maxii=max(maxii,grid[i-1][j])
                if i+1<len(grid) and grid[i+1][j]==1:
                    grid[i+1][j]=grid[i][j]+1
                    queue.append([i+1,j])
                    maxii=max(maxii,grid[i+1][j])
                if j-1>=0 and grid[i][j-1]==1:
                    grid[i][j-1]=grid[i][j]+1
                    queue.append([i,j-1])
                    maxii=max(maxii,grid[i][j-1])
                if j+1<len(grid[0]) and grid[i][j+1]==1:
                    grid[i][j+1]=grid[i][j]+1
                    queue.append([i,j+1])
                    maxii=max(maxii,grid[i][j+1])
                
            #IF STILL 1 present in grid
            for i in grid:
                if 1 in i:
                    return -1
            return maxii-5
        
    
