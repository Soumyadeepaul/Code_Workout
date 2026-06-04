#https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/?envType=study-plan-v2&envId=top-interview-150
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices)==1:
            return 0

        minima=10**9+7
        profit=0
        #FIND LOCAL MINIMA AND LOCAL MAXIMA
        for i in range(len(prices)):
            if i-1==-1:
                if prices[i]<=prices[i+1]:
                    minima=prices[i]
            elif i+1<len(prices):
                if prices[i]<=prices[i+1] and prices[i]<=prices[i-1]:
                    minima=prices[i]
            if minima!=10**9+7:
                if i+1<len(prices) and prices[i]>=prices[i+1] and prices[i]>=prices[i-1]:
                    profit+=prices[i]-minima
                    minima=10**9+7
                elif i+1==len(prices) and prices[i]>minima:
                    profit+=prices[i]-minima
                    minima=10**9+7
        return profit
///////////////////////////////////////////////////////

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        bool sell=false;
        int profit=0;
        int buy=INT_MAX;
        int sell_day=0;
        prices.push_back(INT_MIN);
        for(int i:prices){
            if(sell==false){
                if(buy>i) buy=i;
                else sell=true;
            }
            if(sell==true){
                if(sell_day<i) sell_day=i;
                else {
                    profit+=sell_day-buy;
                    sell_day=0;
                    sell=false;
                    buy=i;
                }
            }
        }
        return profit;
    }
};

///////////////////////////////////////////////////////

class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int>& prices, int idx, bool buy){
        if(idx==prices.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy){
            return dp[idx][buy]=max(helper(prices,idx+1,false)-prices[idx],helper(prices,idx+1,true));
        }
        else{
            return dp[idx][buy]=max(helper(prices,idx+1,true)+prices[idx],helper(prices,idx+1,false));
        }

    }
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(),vector<int> (2,-1));
        return helper(prices,0,true);
    }
};
