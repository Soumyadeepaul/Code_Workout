//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

class Solution {
public:
    int result=0;
    vector<vector<int>>dp;
    int helper(vector<int>& prices, int fee, int idx,bool toBuy){
        if(idx==prices.size()){
            return 0;
        }
        if(dp[idx][toBuy]!=-1) return dp[idx][toBuy];
        if(toBuy){
            dp[idx][toBuy]=max(helper(prices,fee,idx+1,0)-prices[idx]-fee,helper(prices,fee,idx+1,1));
        }
        else{
            dp[idx][toBuy]=max(helper(prices,fee,idx+1,1)+prices[idx],helper(prices,fee,idx+1,0));
        }
        return dp[idx][toBuy];
    }
    int maxProfit(vector<int>& prices, int fee) {
        dp.resize(prices.size(),vector<int>(2,-1));
        
        return helper(prices,fee,0,1);
    }
};
