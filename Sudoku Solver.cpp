//https://leetcode.com/problems/sudoku-solver/description/?envType=problem-list-v2&envId=backtracking

class Solution {
private:
public:
    bool isSafe(vector<vector<char>>& board,int i,int j,char k){
        //check row
        for(int y=0;y<9;y++){
            if(board[i][y]==k) return false;
        }

        //col
        for(int x=0;x<9;x++){
            if(board[x][j]==k) return false;
        }

        //box
        int r=i-(i%3),c=j-(j%3);
        for(int x=r;x<r+3;x++){
            for(int y=c;y<c+3;y++){
                if(board[x][y]==k) return false;
            }
        }
        return true;
    }


    bool helper(vector<vector<char>>& board,int i,int j)
    {
        if (i==9) return true;
        int nextRow=i,nextCol=j+1;
        if(nextCol==9){
            nextRow++;
            nextCol=0;
        }
        if(board[i][j]!='.'){
            return helper(board,nextRow,nextCol);
        }
        for(char k='1';k<='9';k++){
            if(isSafe(board,i,j,k)){
                board[i][j]=k;
                if(helper(board,nextRow,nextCol)) return true;
                board[i][j]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);
    }
};
