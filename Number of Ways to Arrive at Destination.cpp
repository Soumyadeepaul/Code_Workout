//https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/



class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const long long MOD = 1e9 + 7;

        vector<vector<pair<int,int>>> adj(n);

        for (auto &r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if (cost > dist[node]) continue;

            for (auto &[nei, wt] : adj[node]) {

                long long newCost = cost + wt;

                if (newCost < dist[nei]) {
                    dist[nei] = newCost;
                    ways[nei] = ways[node];
                    pq.push({newCost, nei});
                }
                else if (newCost == dist[nei]) {
                    ways[nei] = (ways[nei] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};
