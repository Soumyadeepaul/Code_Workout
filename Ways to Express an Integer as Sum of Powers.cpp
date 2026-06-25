//https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/description/


class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<int> store;
        for(int i=0;i<=n;i++){
            long long val=pow(i,x);
            if(val>n) break;
            store.push_back(val);
        }
        int l=store.size();
        vector<vector<int>> dp(l,vector<int>(n+1,0));
        int MOD=1e9+7;
        for(int i=0;i<l;i++) dp[i][0]=1;

        for(int i=1;i<l;i++){
            for(int j=1;j<n+1;j++){
                if(store[i]>j) {
                    dp[i][j]=dp[i-1][j];
                }
                else {
                    dp[i][j]=(dp[i-1][j]+dp[i-1][j-store[i]])%MOD;
                }
            }
        }
        return dp[l-1][n];
    }
};
