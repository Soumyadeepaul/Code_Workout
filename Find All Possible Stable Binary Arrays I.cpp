//https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i/description/?envType=daily-question&envId=2026-03-09


class Solution {
public:
    int mod=1e9 + 7;
    int helper(int zero, int one, int &limit, int prev, vector<vector<vector<int>>> &dp){

        if(zero==0 && one == 0){
            return 1;
        }
        if(dp[zero][one][prev]!=-1) return dp[zero][one][prev];
        int result=0;
        for(int i=1;i<=limit;i++){
            if(prev==1 && zero>=i){
                result=(result+ helper(zero-i,one,limit,0, dp))%mod;
            }
            if(prev==0 && one>=i){
                result=(result+helper(zero,one-i,limit,1, dp))%mod;
            }
        }
        return dp[zero][one][prev]=result%mod;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<int>>> dp(
            zero+1,
            vector<vector<int>>(one+1, vector<int>(2, -1))
        );
        int v1=helper(zero,one,limit, 1, dp);
        int v2=helper(zero,one,limit, 0, dp);
        return (v1+v2)%mod;
    }
};
