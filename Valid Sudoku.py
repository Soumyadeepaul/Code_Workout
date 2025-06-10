#https://leetcode.com/problems/valid-sudoku/description/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        for i in range(len(board)):
            presentRow=set()
            presentCol=set()
            for j in range(len(board)):
                
                #row
                if board[i][j]=='.':
                    pass
                elif board[i][j] in presentRow:
                    return False
                else:
                    presentRow.add(board[i][j])

                #col
                if board[j][i]=='.':
                    pass
                elif board[j][i] in presentCol:
                    return False
                else:
                    presentCol.add(board[j][i])
        


        for i in range(0,len(board),3):
            for j in range(0,len(board),3):
                #############################
                present=set()
                for x in range(i,i+3):
                    for y in range(j,j+3):
                        if board[x][y]=='.':
                            pass
                        elif board[x][y] in present:
                            return False
                        else:
                            present.add(board[x][y])
        return True
