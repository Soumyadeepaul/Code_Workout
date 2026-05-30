//https://leetcode.com/problems/minimum-cost-path-with-alternating-directions-ii/description/


class Solution {
public:
    int cal(int i,int j){
        return (i+1)*(j+1);
    }
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<long long>> dp(m,vector<long long> (n));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=cal(i,j);
                if(!(i==0 && j==0)){
                    dp[i][j]+=waitCost[i][j];
                } 
            }
        }

        for(int i=m-1;i>-1;i--){
            for(int j=n-1;j>-1;j--){
                if(i==m-1 && j==n-1) continue;
                else if(i==m-1) dp[i][j]+=dp[i][j+1];
                else if(j==n-1) dp[i][j]+=dp[i+1][j];
                else{
                    dp[i][j]+=min(dp[i+1][j],dp[i][j+1]);
                }
            }
        }

        return dp[0][0]-waitCost[m-1][n-1];
    }
};
