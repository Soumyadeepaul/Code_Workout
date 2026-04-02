//https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/description/


class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int r=coins.size(),c=coins[0].size();
        int neg=-1e9;
        vector<vector<vector<int>>> dp(r,vector<vector<int>> (c,{neg,neg,neg})); //0 1 2 neutralize
        for(int i=r-1;i>-1;i--){
            for(int j=c-1;j>-1;j--){
                if(i==r-1 && j==c-1){
                    dp[i][j][0]=coins[i][j];
                    dp[i][j][1]=max(coins[i][j],0);
                    dp[i][j][2]=max(coins[i][j],0);
                }
                else if(i== r-1){
                    vector<int> adj1=dp[i][j+1];
                    dp[i][j][0]=coins[i][j]+adj1[0];

                    dp[i][j][1]=max(
                        coins[i][j]+adj1[1],
                        0+adj1[0]
                    );

                    dp[i][j][2]=max(
                        coins[i][j]+adj1[2],
                        0+adj1[1]
                    );
                }
                else if(j== c-1){
                    vector<int> adj1=dp[i+1][j];
                    dp[i][j][0]=coins[i][j]+adj1[0];

                    dp[i][j][1]=max(
                        coins[i][j]+adj1[1],
                        0+adj1[0]
                    );

                    dp[i][j][2]=max(
                        coins[i][j]+adj1[2],
                        0+adj1[1]
                    );
                }
                else {
                    vector<int> adj1=dp[i][j+1];
                    vector<int> adj2=dp[i+1][j];
                    dp[i][j][0]=coins[i][j]+max(adj1[0],adj2[0]);
                    dp[i][j][1]=max(
                        coins[i][j]+max(adj1[1],adj2[1]),
                        0+max(adj1[0],adj2[0])
                    );
                    dp[i][j][2]=max(
                        coins[i][j]+max(adj1[2],adj2[2]),
                        0+max(adj1[1],adj2[1])
                    );
                }
            }
        }
        
        return *max_element(dp[0][0].begin(),dp[0][0].end());
    }
};
