#https://leetcode.com/problems/maximal-square/

class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        maxi=0
        for i in range(len(matrix)-1,-1,-1):
            for j in range(len(matrix[0])-1,-1,-1):
                if matrix[i][j]=='0':
                    matrix[i][j]=0
                else:
                    down=0
                    if i+1<len(matrix):
                        down=int(matrix[i+1][j])

                    right=0
                    if j+1< len(matrix[0]):
                        right=int(matrix[i][j+1])
                    
                    diagonal=0
                    if j+1<len(matrix[0]) and i+1<len(matrix):
                        diagonal=int(matrix[i+1][j+1])
                    matrix[i][j]=1+min(down,right,diagonal)
                    
                    if maxi<matrix[i][j]:
                        maxi=matrix[i][j]
        return maxi*maxi
        
