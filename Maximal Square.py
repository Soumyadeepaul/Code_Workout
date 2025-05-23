#https://leetcode.com/problems/maximal-square/

class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        #TABULATION BOTTOM UP
        # maxi=0
        # for i in range(len(matrix)-1,-1,-1):
        #     for j in range(len(matrix[0])-1,-1,-1):
        #         if matrix[i][j]=='0':
        #             matrix[i][j]=0
        #         else:
        #             down=0
        #             if i+1<len(matrix):
        #                 down=int(matrix[i+1][j])

        #             right=0
        #             if j+1< len(matrix[0]):
        #                 right=int(matrix[i][j+1])
                    
        #             diagonal=0
        #             if j+1<len(matrix[0]) and i+1<len(matrix):
        #                 diagonal=int(matrix[i+1][j+1])
        #             matrix[i][j]=1+min(down,right,diagonal)

        #             if maxi<matrix[i][j]:
        #                 maxi=matrix[i][j]
        # return maxi*maxi
        #################################################

        
        #TOP DOWN

        def square(mat,i,j,maxi,dp):
            if i>=len(mat) or j>=len(mat[0]):
                return (0,maxi)
            if dp[i][j]!=-1:
                return (dp[i][j],maxi)
                
            right,maxi=square(mat,i,j+1,maxi,dp)
            diagonal,maxi=square(mat,i+1,j+1,maxi,dp)
            down,maxi=square(mat,i+1,j,maxi,dp)

            if mat[i][j]=='1':
                dp[i][j]=1+min(right,down,diagonal)
                maxi=max(dp[i][j],maxi)
                return (dp[i][j],maxi)
            else:
                dp[i][j]=0
                return (dp[i][j],maxi)

        dp=[[-1 for _ in range(len(matrix[0]))]for _ in range(len(matrix))]
        maxi=0
        _,maxi=square(matrix,0,0,maxi,dp)

        return maxi*maxi




        
        
