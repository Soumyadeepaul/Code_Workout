//https://leetcode.com/problems/integer-break/description/?envType=problem-list-v2&envId=dynamic-programming

class Solution {
public:
    int helper(int &n, int total,vector<int> &dp){
        if(total<=0) return dp[0]=1;
        if(dp[total]!=0) return dp[total];
        for(int i=1;i<n;i++){
            if(total-i<0) return dp[total];
            dp[total]=max(dp[total],i*helper(n,total-i,dp));
        }
        return dp[total];
    }
    int integerBreak(int n) {
        int total=n;
        vector<int> dp(n+1,0);
        int result= helper(n,total,dp);
        return result;
    }
};
