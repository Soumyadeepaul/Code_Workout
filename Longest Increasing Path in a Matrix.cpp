//https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/?envType=problem-list-v2&envId=graph


class Solution {
private:
    int row,col;
    int dfs(vector<vector<int>>& matrix,int i,int j,vector<vector<bool>> &visited,vector<vector<int>> &dp,int &result){
        if(visited[i][j]==true) return dp[i][j];
        //up
        int up=0;
        if(i-1>-1 && matrix[i-1][j]>matrix[i][j]){
            up=1+dfs(matrix,i-1,j,visited,dp,result);
        }
        //down
        int down=0;
        if(i+1<row && matrix[i+1][j]>matrix[i][j]){
            down=1+dfs(matrix,i+1,j,visited,dp,result);
        }
        //left
        int left=0;
        if(j-1>-1 && matrix[i][j-1]>matrix[i][j]){
            left=1+dfs(matrix,i,j-1,visited,dp,result);
        }

        //right
        int right=0;
        if(j+1<col && matrix[i][j+1]>matrix[i][j]){
            right=1+dfs(matrix,i,j+1,visited,dp,result);
        }
        dp[i][j]=max(up,max(down,max(left,right)));
        result=max(result,dp[i][j]);
        visited[i][j]=true;
        return dp[i][j];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        row=matrix.size(),col=matrix[0].size();

        //dfs
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        vector<vector<int>> dp(row,vector<int>(col,0));//stores maximum length
        
        int result=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(visited[i][j]==true) continue;
                //////
                int temp=dfs(matrix,i,j,visited,dp,result);
            }
        }
        return 1+result;
        
    }
};
