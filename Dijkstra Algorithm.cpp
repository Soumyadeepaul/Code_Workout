//https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1



class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

        vector<vector<pair<int,int>>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<int> dist(V, 1e9);
        dist[src] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if (cost > dist[node]) continue;

            for (auto &p : adj[node]) {
                int next = p.first;
                int wt   = p.second;

                if (cost + wt < dist[next]) {
                    dist[next] = cost + wt;
                    pq.push({dist[next], next});
                }
            }
        }
        return dist;
    }
};
