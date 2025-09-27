//https://leetcode.com/problems/game-of-life/description/?envType=study-plan-v2&envId=top-interview-150


class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> dp=board;
        int row=dp.size();
        int col=dp[0].size();
        int count;
        for(int i=0;i<row;i++){ 
            for(int j=0;j<col;j++){
                count=0;
                if(i-1>-1 && dp[i-1][j]==1) count++;
                if(i-1>-1 && j-1>-1 && dp[i-1][j-1]==1) count++;
                if(j-1>-1 && dp[i][j-1]==1) count++;
                if(i+1<row && dp[i+1][j]==1) count++;
                if(i+1<row && j+1<col && dp[i+1][j+1]==1) count++;
                if(i+1<row && j-1>-1 && dp[i+1][j-1]==1) count++;
                if(j+1<col && dp[i][j+1]==1) count++;
                if(i-1>-1 && j+1<col && dp[i-1][j+1]==1) count++;

                if(dp[i][j]==0){
                    if (count==3){
                        board[i][j]=1;
                    }
                }
                else{
                    if(count==2 || count==3){}
                    else{
                        board[i][j]=0;
                    }
                }
            }
        }
    }
};
