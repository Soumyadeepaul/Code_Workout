//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/


class Solution {
public:
    vector<vector<vector<int>>>dp;
    int helper(int idx, vector<int>& prices, bool cool,bool toBuy){
        if(idx==prices.size()) {
            return 0;
        }
        if(dp[idx][cool][toBuy]!=-1) return dp[idx][cool][toBuy];
        if(toBuy){
            if(cool) dp[idx][cool][toBuy]=helper(idx+1,prices,!cool,toBuy);
            else{
                dp[idx][cool][toBuy]=helper(idx+1,prices,cool,!toBuy)-prices[idx];
                dp[idx][cool][toBuy]=max(dp[idx][cool][toBuy],helper(idx+1,prices,cool, toBuy));
            }
        }
        else{
            dp[idx][cool][toBuy]=helper(idx+1,prices,!cool, !toBuy) +prices[idx];
            dp[idx][cool][toBuy]=max(dp[idx][cool][toBuy],helper(idx+1,prices,cool, toBuy));
        }
        return dp[idx][cool][toBuy];
    }
    int maxProfit(vector<int>& prices) {
        dp.assign(prices.size(),vector<vector<int>>(2, vector<int> (2,-1)));
        return helper(0,prices,0,1);
    }
};
