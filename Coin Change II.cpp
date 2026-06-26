//https://leetcode.com/problems/coin-change-ii/description/?envType=problem-list-v2&envId=dynamic-programming


class Solution {
public:
long long  MOD=LLONG_MAX;
    int change(int amount, vector<int>& coins) {
        vector<long long unsigned> dp(amount+1,0);
        dp[0]=1;
        for(int i=0;i<coins.size();i++){
            for(int j=0;j<amount+1;j++){
                if(j-coins[i]>=0)
                dp[j]=(long long unsigned)((long long unsigned)dp[j]+(long long unsigned)dp[j-coins[i]])%MOD;
            }
        }
        return (int)dp[amount];
    }
};
