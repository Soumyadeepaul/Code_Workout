//https://leetcode.com/problems/wildcard-matching/description/


class Solution {
public:
    bool helper(string &s, string &p, int i, int j, vector<vector<int>> &dp) {

        // ---- base cases ----
        if (i == s.size() && j == p.size())
            return true;

        if (j == p.size())
            return false;

        if (i == s.size()) {
            // remaining pattern must be all '*'
            while (j < p.size() && p[j] == '*') j++;
            return j == p.size();
        }
        if(dp[i][j]!=-1) return dp[i][j];

        // ---- recursive cases ----
        if (p[j] == '*') {
            // not use '*' OR use it
            return dp[i][j]=(helper(s, p, i, j + 1,dp) || helper(s, p, i + 1, j,dp));
        }

        if (p[j] == '?' || p[j] == s[i]) {
            return dp[i][j]=helper(s, p, i + 1, j + 1,dp);
        }

        return false;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(),vector<int> (p.size(),-1));
        return helper(s, p, 0, 0, dp);
    }
};
