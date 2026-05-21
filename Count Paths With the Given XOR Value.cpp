//https://leetcode.com/problems/count-paths-with-the-given-xor-value/description/


class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int rows=grid.size()-1,cols=grid[0].size()-1;
        vector<vector<unordered_map<int,long long>>> dp(rows+1,vector<unordered_map<int,long long>> (cols+1));
        int mod=1e9+7;
        for(int i=rows;i>-1;i--){
            for(int j=cols;j>-1;j--){
                if(i==rows && j==cols){
                    dp[i][j][grid[i][j]]=1;
                }
                else if(i==rows){
                    for(auto p: dp[i][j+1]){
                        dp[i][j][grid[i][j]^p.first]=(dp[i][j][grid[i][j]^p.first]+p.second)%mod;
                    }
                }
                else if(j==cols){
                    for(auto p: dp[i+1][j]){
                        dp[i][j][grid[i][j]^p.first]=(dp[i][j][grid[i][j]^p.first]+p.second)%mod;
                    }
                }
                else{
                    for(auto p: dp[i][j+1]){
                        dp[i][j][grid[i][j]^p.first]=(dp[i][j][grid[i][j]^p.first]+p.second)%mod;
                    }
                    for(auto p: dp[i+1][j]){
                        dp[i][j][grid[i][j]^p.first]=(dp[i][j][grid[i][j]^p.first]+p.second)%mod;
                    }
                }
            }
        }
        return dp[0][0][k];
    }
};
