//https://leetcode.com/problems/flip-string-to-monotone-increasing/description/


class Solution {
public:
    int helper(string &s, vector<vector<int>> &dp, int idx, int one){
        if(idx == s.size()) return 0;

        if(dp[idx][one] != -1) return dp[idx][one];

        if(one == 1){
            if(s[idx] == '0'){
                return dp[idx][one] = 1 + helper(s, dp, idx+1, 1); //flip to 1
            }
            else{
                return dp[idx][one] = helper(s, dp, idx+1, 1); // no change as 1
            }
        }
        else{
            if(s[idx] == '1'){
                int c1 = 1 + helper(s, dp, idx+1, 0); // flip to 0
                int c2 = helper(s, dp, idx+1, 1);     // start 1-phase
                return dp[idx][one] = min(c1, c2);
            }
            else{
                return dp[idx][one] = helper(s, dp, idx+1, 0);
            }
        }
    }

    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(s, dp, 0, 0);
    }
};
