//https://leetcode.com/problems/perfect-squares/description/


class Solution {
public:
    int helper(int n, vector<int>& dp) {
        if (n == 0) return dp[0] = 0;
        if (dp[n] != -1) return dp[n];

        int best = INT_MAX;
        for (int i = 1; i * i <= n; ++i) {
            int val = i * i;
            if(val>n) break;
            best = min(best, 1 + helper(n - val, dp));
        }
        return dp[n] = best;
    }

    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        return helper(n, dp);
    }
};
