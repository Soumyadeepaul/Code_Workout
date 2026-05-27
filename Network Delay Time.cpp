//https://leetcode.com/problems/network-delay-time/description/



class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> grp;
        for(auto i:times){
            grp[i[0]].push_back({i[1],i[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int result=-1;
        pq.push({0,k});
        vector<int> visited(n+1,0);
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            int node=p.second, dis=p.first;
            if(visited[node]!=1) result=max(result,dis); // if visited for 1st time, sure that it will be smaller delay
            visited[node]=1;
            for(auto &nei:grp[node]){
                if(visited[nei.first]!=1){
                    int newD=dis+nei.second;
                    pq.push({newD,nei.first});
                }
            }
            grp.erase(node);
        }
        for(int i=1;i<visited.size();i++) if(visited[i]==0) return -1;
        return (result==0) ? -1 : result;
    }
};
