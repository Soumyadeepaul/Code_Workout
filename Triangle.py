#https://leetcode.com/problems/triangle/description/?envType=study-plan-v2&envId=top-interview-150


class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:

        for i in range(len(triangle[len(triangle)-1])):
            triangle[len(triangle)-1][i]=[triangle[len(triangle)-1][i]]

        for i in range(len(triangle)-2,-1,-1):
            for j in range(len(triangle[i])):
                

                a=i+1
                b1=j
                b2=j+1
                node1=triangle[a][b1]
                node2=triangle[a][b2]
                result=[]
                val=triangle[i][j]
                for x in node1:
                    result.append(x+val)
                for x in node2:
                    result.append(x+val)
                triangle[i][j]=[min(result)]
        
        # for i in triangle:
        #     print(i)
        
        return min(triangle[0][0])
        
