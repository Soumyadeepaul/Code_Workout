//https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i/description/?envType=daily-question&envId=2026-06-11



class Solution {
public:
    int mod=1e9+7;
    long long power(int r){
        long long result=1;
        long long p=2;
        while(r){
            if(r&1) result=(result*p)%mod;
            p=(p*p)%mod;
            r>>=1;
        }
        return result;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int node=edges.size()+1;
        unordered_map<int,vector<int>> adjList;
        for(auto e:edges) {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        vector<int> visited(node+1,0);
        queue<pair<int,int>> q; //node, level
        int maxHeight=0;
        q.push({1,0});
        while(!q.empty()){
            auto n=q.front();
            q.pop();
            int node=n.first, height=n.second;
            maxHeight=max(height,maxHeight);
            visited[node]=1;
            for(auto e:adjList[node]){
                if(visited[e]==0)
                q.push({e,height+1});
            }
        }
        return (int)power(maxHeight-1);
    }
};
