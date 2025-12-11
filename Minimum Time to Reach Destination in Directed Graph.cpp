//https://leetcode.com/problems/minimum-time-to-reach-destination-in-directed-graph/description/


class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        //bfs
        unordered_map<int,vector<vector<int>>> map;
        unordered_map<int,int> visited;
        for(auto e:edges){
            vector<int> b(e.begin()+1,e.end());
            map[e[0]].push_back(b);
        }
        int result=INT_MAX;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,0}); //time,node
        int count=0;
        while(!q.empty()){
            auto [time, node] = q.top();
            q.pop();
            if(visited.count(node) && visited[node]<=time)
                continue;
            if(node==n-1){
                result=min(result,time);
                break;
            }
            visited[node]=time;
            vector<vector<int>> extract=map[node];

            for(vector<int> ed:extract){
                int timeNew=max(time,ed[1]);
                if(timeNew>ed[2]) continue; //arrives late
                q.push({timeNew+1,ed[0]});
            }
        }
        return (result==INT_MAX) ? -1 : result;
    }
};
