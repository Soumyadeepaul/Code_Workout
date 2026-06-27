//https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset/description/?envType=daily-question&envId=2026-06-27


class Solution {
public:
    int custom(int n, int x){
        long long p=n;
        long long val=1;
        while(x){
            if(x&1){
                val=1ll*val*p;
                if(val>1e9) return 0;
            }
            x>>=1;
            p=1ll*p*p;
        }
        return val;
    }

    int loop(int n, unordered_map<int,int> &freq,unordered_map<int,int> &dp, int power){
        if(dp.count(n)) return dp[n];

        // Current number itself must appear twice to contribute both sides.
        if(freq[n] < 2)
            return dp[n] = 1;

        int find = custom(n, power);

        if(find == 0 || !freq.count(find))
            return dp[n] = 1;

        dp[n] = 2 + loop(find, freq, dp, 2);
        return dp[n];
    }
    int maximumLength(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i:nums) freq[i]++;
        unordered_map<int,int> dp;
        int result=1;
        for(auto p: freq){
            if(p.first==1) {
                dp[1]=(freq[1]%2==0)?freq[1]-1:freq[1];
            }
            else{
                loop(p.first,freq,dp,2);
            }
            result=max(result,dp[p.first]);
        }
        return result;

    }
};
