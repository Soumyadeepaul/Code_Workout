//https://leetcode.com/problems/minimum-falling-path-sum/description/


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        int minn=INT_MAX;
        for(int i=n-1;i>-1;i--){
            for(int j=0;j<n;j++){
                if(i==n-1) dp[i][j]=matrix[i][j];
                if(i-1>-1){
                    dp[i-1][j]=min(dp[i][j]+matrix[i-1][j],dp[i-1][j]);
                    if(j-1>-1)
                    dp[i-1][j-1]=min(dp[i][j]+matrix[i-1][j-1],dp[i-1][j-1]);
                    if(j+1<n)
                    dp[i-1][j+1]=min(dp[i][j]+matrix[i-1][j+1],dp[i-1][j+1]);
                }
                else{
                    minn=min(minn,dp[i][j]);
                }
            }
        }
        return minn;
    }
};
