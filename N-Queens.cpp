//https://leetcode.com/problems/n-queens/

class Solution {
public:
    bool check(vector<string> & board,int &i,int &j,int &n){
        //up col
        int x=i-1;
        int y=j;
        while (x>-1){
            if(board[x][y]=='Q') return false;
            x--;
        }
        //back dia up
        x=i-1;
        y=j-1;
        while(x>-1 && y>-1){
            if(board[x][y]=='Q') return false;
            x--;
            y--;
        }

        // forward dia up
        x=i-1;
        y=j+1;
        while(x>-1 && y<n){
            if(board[x][y]=='Q') return false;
            x--;
            y++;
        }
        return true;

    }
    void queen(vector<string> &board,int &rowNum, int &n,vector<vector<string>> &result){
        if (rowNum==n){
            result.push_back(board);
            return;
        } 
        for(int y=0;y<n;y++){
            board[rowNum][y]='Q';
            if(check(board,rowNum,y,n)==true){
                rowNum++;
                queen(board,rowNum,n,result);
                rowNum--;
            }
            board[rowNum][y]='.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>   result;
        vector<string> board;
        string s;
        for(int i=0;i<n;i++){
            s="";
            for(int j=0;j<n;j++){
                s=s+".";
            }
            board.push_back(s);
        }
        int rowNum=0;
        queen(board,rowNum,n,result);
        return result;
    }
};
