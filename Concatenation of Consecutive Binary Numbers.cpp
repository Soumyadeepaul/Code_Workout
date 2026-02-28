//https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/description/?envType=daily-question&envId=2026-02-28


class Solution {
public:
    int concatenatedBinary(int n) {
        vector<string> dp(n+1,"");
        dp[1]="1";
        for(int i=2;i<=n;i++){
            dp[i]=dp[i>>1]+to_string(i&1);
        }
        long long result=0;
        int mod=pow(10,9)+7;
        long long power=1;
        for(int i=n;i>=1;i--){
            for(int j=dp[i].size()-1;j>-1;j--){
                if(dp[i][j]=='1') result=(result+power)%mod;
                power=(power<<1)%mod;
            }
        }
        return result;
    }
};
