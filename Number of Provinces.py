#https://leetcode.com/problems/number-of-provinces/description/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        visited={}
        provinces=0
        for i in range(len(isConnected)):
            for j in range(len(isConnected[i])):
                if isConnected[i][j]==1:
                    if j not in visited:
                        visited[j]=set([i])
                    else:
                        visited[j].add(i)
        # 0: [0,3], 3: [0,1,3]
        #then making 0:[0,1,3], and 0 can indirectlt reach 1         
        for i in visited.items():
            for j in i[1]:
                for k in i[1]:
                    visited[j].add(k)

        visitedNode=[]
        for i in visited.values():
            if i not in visitedNode:
                visitedNode.append(i)

        return len(visitedNode)
        
