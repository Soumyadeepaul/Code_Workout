//https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int result = 1;
        for (int& i : arr) {
            dp[i] = 1 + dp[i - difference];
            result = max(result, dp[i]);
        }
        return result;
    }
};
