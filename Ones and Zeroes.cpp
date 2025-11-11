//https://leetcode.com/problems/ones-and-zeroes/description/?envType=daily-question&envId=2025-11-11

class Solution {
public:
    int helper(vector<pair<int,int>> &st, int i, int l,
               int zerosUsed, int onesUsed, int m, int n,
               unordered_map<string, int> &dp) {

        // Base case
        if (i == l) return 0;

        // Unique key for this state
        //dp not only depend on index but also on left out 0 and 1
        string key = to_string(i) + "|" + to_string(zerosUsed) + "|" + to_string(onesUsed);
        if (dp.count(key)) return dp[key];

        int notTake = helper(st, i + 1, l, zerosUsed, onesUsed, m, n, dp);

        int take = 0;
        if (zerosUsed + st[i].first <= m && onesUsed + st[i].second <= n) {
            take = 1 + helper(st, i + 1, l,
                              zerosUsed + st[i].first,
                              onesUsed + st[i].second,
                              m, n, dp);
        }

        return dp[key] = max(take, notTake);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int l = strs.size();
        vector<pair<int,int>> st(l);

        for (int j = 0; j < l; j++) {
            int zeros = 0, ones = 0;
            for (char c : strs[j]) {
                if (c == '0') zeros++;
                else ones++;
            }
            st[j] = {zeros, ones};
        }

        unordered_map<string, int> dp;
        return helper(st, 0, l, 0, 0, m, n, dp);
    }
};
