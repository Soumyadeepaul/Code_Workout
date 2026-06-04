//https://leetcode.com/problems/path-with-maximum-probability/description/?envType=problem-list-v2&envId=graph


class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        unordered_map<int,vector<vector<double>>> adj; //start:{{end,prob},{....}}

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({(double)edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({(double)edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>> pq;
        pq.push({1,start_node});
        vector<int> visited(n,0);
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int node=top.second;
            double prob=top.first;
            if(node==end_node) return prob;

            visited[node]=1;

            for(auto p:adj[node]){
                if(!visited[(int)p[0]]){
                    pq.push({p[1]*prob,(int)p[0]});
                }
            }
        }

        return 0;
    }
};
