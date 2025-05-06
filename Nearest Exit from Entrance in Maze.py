#https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/?envType=study-plan-v2&envId=leetcode-75
class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        #BFS
        queue=[entrance]
        maze[entrance[0]][entrance[1]]=0 #marking the level inplace #VISITED
        while queue:
            position=queue.pop(0)

            i=position[0]
            j=position[1]

            if (i==0 or j==0 or i==len(maze)-1 or j==len(maze[0])-1) and (i!=entrance[0] or j !=entrance[1]): #BASE CASE
                return maze[i][j]

            if i-1>-1 and maze[i-1][j]=='.':
                maze[i-1][j]=maze[i][j]+1 #MARKING THE LEVEL +1
                queue.append([i-1,j]) #inserting in queue
            if i+1<len(maze) and maze[i+1][j]=='.':
                maze[i+1][j]=maze[i][j]+1
                queue.append([i+1,j])
            if j-1>=0 and maze[i][j-1]=='.':
                maze[i][j-1]=maze[i][j]+1
                queue.append([i,j-1])
            if j+1<len(maze[0]) and maze[i][j+1]=='.':
                maze[i][j+1]=maze[i][j]+1
                queue.append([i,j+1])
        return -1
        
################
#LOGIC
#[[+,+,.]
# [+,.,.]]

#[[+,+,.]
# [+,0,.]]

#[[+,+,.]
# [+,0,1]]
