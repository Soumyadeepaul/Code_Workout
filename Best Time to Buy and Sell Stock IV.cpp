//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

class Solution {
public:
    vector<vector<vector<int>>> dp;
    int helper(int k,vector<int>& prices, int idx, bool toBuy){
        if(idx==prices.size() || k<=0) return 0;
        if(dp[idx][k][toBuy]!=-1) return dp[idx][k][toBuy];
        if(toBuy){
            dp[idx][k][toBuy]=helper(k,prices,idx+1,0)-prices[idx]; //bought
            dp[idx][k][toBuy]=max(dp[idx][k][toBuy],helper(k,prices,idx+1,1)); //not bought
        }
        else {
            dp[idx][k][toBuy]=helper(k-1, prices, idx+1,1)+prices[idx]; //sold
            dp[idx][k][toBuy]=max(dp[idx][k][toBuy],helper(k, prices, idx+1,0)); //not sold
        }
        return dp[idx][k][toBuy];
    }
    int maxProfit(int k, vector<int>& prices) {
        dp.assign(prices.size(),vector<vector<int>>(k+1,vector<int>(2,-1)));
        return helper(k,prices,0,1);
    }
};
