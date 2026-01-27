//https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/?envType=daily-question&envId=2026-01-27

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<pair<int,int>>> map;
        for(auto e:edges){
            map[e[0]].push_back({e[1],e[2]});
            map[e[1]].push_back({e[0],2*e[2]});
        }
        vector<int> dist(n,INT_MAX);
        dist[0]=0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0,0});
        while(!q.empty()){
            vector<int> uvc=q.top();
            q.pop();
            int v=uvc[1],c=uvc[0];
            if(c>dist[v]) continue;
            for(auto i:map[v]){
                if(i.second+c<dist[i.first]) {
                    dist[i.first]=i.second+c;
                    q.push({dist[i.first],i.first});
                }
            }
        }
        return (dist[n-1]==INT_MAX) ? -1:dist[n-1];
    }
};
