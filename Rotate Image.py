#https://leetcode.com/problems/rotate-image/description/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        
        #Transpose
        for i in range(len(matrix)):
            for j in range(i,len(matrix)):
                matrix[i][j],matrix[j][i]=matrix[j][i],matrix[i][j]
        
        j=0
        k=len(matrix[0])-1
        for i in matrix:
            while j<k:
                i[j],i[k]=i[k],i[j]
                j+=1
                k-=1
            j=0
            k=len(matrix[0])-1
