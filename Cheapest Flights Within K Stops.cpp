//https://leetcode.com/problems/cheapest-flights-within-k-stops/description/


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //single source shortest path
        //therefore Dijkstra -- {NO USE HERE}

        //adj list
        unordered_map<int,unordered_map<int,int>> map; // n1: n2: cost
        for(auto &f:flights){
            map[f[0]][f[1]]=f[2];
        }

        //it uses min heap... pq  -- NOT USED
        queue<vector<int>> pq;
        //store cost, steps, current Node
        pq.push({0,-1,src});

        vector<int> dp(n,INT_MAX);
        dp[src]=0;
        int result=INT_MAX;
        while(!pq.empty()){
            auto node=pq.front();
            pq.pop();
            int cost=node[0], steps=node[1], Cnode=node[2];
            if(steps>k) continue;
            if(Cnode==dst){
                result=min(result,cost);
                continue;
            }
            unordered_map<int,int> &neigh=map[Cnode];

            for(auto &nei:neigh){
                if(dp[nei.first]<(cost+nei.second)) continue; 
                dp[nei.first]=cost+nei.second; //relax
                pq.push({cost+nei.second,steps+1,nei.first});
            }
        }
        return (result==INT_MAX) ? -1 : result;
    }
};
