//https://leetcode.com/problems/minimum-cost-to-convert-string-ii/description/?envType=daily-question&envId=2026-01-30


class Solution {
public:
    long long helper(string &source, string &target,
                     unordered_map<string,int> &nodeIdx,
                     vector<vector<int>> &floyd,
                     unordered_set<int> &validLen) {

        int l = source.size();
        vector<long long> dp(l + 1, 1e18);
        dp[l] = 0;

        for (int i = l - 1; i >= 0; i--) {

            // Case 1: no operation needed
            if (source[i] == target[i])
                dp[i] = dp[i + 1];

            // Case 2: try valid-length substrings
            for (int len : validLen) {
                if (i + len > l) continue;

                string s1 = source.substr(i, len);
                string s2 = target.substr(i, len);

                if (!nodeIdx.count(s1) || !nodeIdx.count(s2)) continue;

                int u = nodeIdx[s1];
                int v = nodeIdx[s2];
                if (floyd[u][v] >= 1e8) continue;

                dp[i] = min(dp[i], (long long)floyd[u][v] + dp[i + len]);
            }
        }

        return dp[0] >= 1e18 ? -1 : dp[0];
    }

    long long minimumCost(string source, string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {

        // Collect unique strings
        set<string> unique;
        for (int i = 0; i < original.size(); i++) {
            unique.insert(original[i]);
            unique.insert(changed[i]);
        }

        vector<string> uniq(unique.begin(), unique.end());
        unordered_map<string,int> nodeIdx;
        for (int i = 0; i < uniq.size(); i++)
            nodeIdx[uniq[i]] = i;

        // Collect valid substring lengths
        unordered_set<int> validLen;
        for (auto &s : original)
            validLen.insert(s.size());

        int n = uniq.size();
        vector<vector<int>> floyd(n, vector<int>(n, 1e8));

        for (int i = 0; i < n; i++)
            floyd[i][i] = 0;

        // Direct costs
        for (int i = 0; i < original.size(); i++) {
            int u = nodeIdx[original[i]];
            int v = nodeIdx[changed[i]];
            floyd[u][v] = min(floyd[u][v], cost[i]);
        }

        // Floyd–Warshall with safety
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (floyd[i][via] < 1e8 && floyd[via][j] < 1e8) {
                        floyd[i][j] = min(floyd[i][j],
                                          floyd[i][via] + floyd[via][j]);
                    }
                }
            }
        }

        return helper(source, target, nodeIdx, floyd, validLen);
    }
};
