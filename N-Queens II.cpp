//https://leetcode.com/problems/n-queens-ii/description/


class Solution {
public:
    bool check(vector<vector<int>> &board,int &rowNum, int &colNum,int &n){
        int i=rowNum;
        int j=colNum;
        while(i>0 && j>0){
            if(board[i-1][j-1]==1){
                return false;
            }
            i--;
            j--;
        }
        i=rowNum;
        j=colNum;
        while(i>0){
            if(board[i-1][j]==1){
                return false;
            }
            i--;
        }
        i=rowNum;
        j=colNum;
        while(i>0 && j+1<n){
            if(board[i-1][j+1]==1){
                return false;
            }
            i--;
            j++;
        }
        return true;
    }


    void queen(vector<vector<int>> &board, int &count, int &n,int rowNum){
        if(rowNum==n){
            count++;
            return;
        }
        for(int i=0;i<n;i++){
            board[rowNum][i]=1;
            if(check(board,rowNum,i,n)){
                queen(board,count,n,rowNum+1);
            }
            board[rowNum][i]=0;
        }
    }
    int totalNQueens(int n) {
        int count=0;
        vector<vector<int>> board(n,vector<int> (n,0));
        queen(board,count,n,0);
        return count;
    }
};
