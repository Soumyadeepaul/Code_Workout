//https://leetcode.com/contest/biweekly-contest-179/problems/minimum-xor-path-in-a-grid/description/



class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int r=grid.size()-1,c=grid[0].size()-1;
        vector<vector<unordered_set<int>>> dp(r+1,vector<unordered_set<int>> (c+1));
        for(int i=r;i>-1;i--){
            for(int j=c;j>-1;j--){
                if(i==r && j==c){
                    dp[i][j].insert(grid[i][j]);
                }
                else if(i==r){
                    for(auto it=dp[i][j+1].begin();it!=dp[i][j+1].end();it++){
                        dp[i][j].insert(grid[i][j]^*it);
                    }
                }
                else if(j==c){
                    for(auto it=dp[i+1][j].begin();it!=dp[i+1][j].end();it++){
                        dp[i][j].insert(grid[i][j]^*it);
                    }
                }
                else{
                    for(auto it=dp[i][j+1].begin();it!=dp[i][j+1].end();it++){
                        dp[i][j].insert(grid[i][j]^*it);
                    }
                    for(auto it=dp[i+1][j].begin();it!=dp[i+1][j].end();it++){
                        dp[i][j].insert(grid[i][j]^*it);
                    }
                }
            }
        }
        return *min_element(dp[0][0].begin(),dp[0][0].end());
    }
};
