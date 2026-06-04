//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/



class Solution {
public:
    vector<vector<vector<int>>> dp;
    int helper(vector<int>& prices, int idx, bool buy, int cap){
        if(idx==prices.size()) return 0;
        if(cap==0) return 0;
        if(dp[idx][buy][cap]!=-1) return dp[idx][buy][cap];
        if(buy){
            return dp[idx][buy][cap]=max(helper(prices,idx+1,false, cap)-prices[idx],helper(prices,idx+1,true,cap));
        }
        else{
            return dp[idx][buy][cap]=max(helper(prices,idx+1,true, cap-1)+prices[idx],helper(prices,idx+1,false,cap));
        }

    }
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(),vector<vector<int>> (2,vector<int>(3,-1)));
        return helper(prices,0,true,2);
    }
};
