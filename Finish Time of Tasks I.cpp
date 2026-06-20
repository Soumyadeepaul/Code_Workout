//


class Solution {
public:
    
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        if(n==1) return baseTime[0];
        vector<vector<int>> map(n);
        vector<int> pending(n);
        for(auto e:edges){
            map[e[1]].push_back(e[0]);
            pending[e[0]]++;
        }
        vector<long long> mini(n,LLONG_MAX);
        vector<long long> maxi(n,LLONG_MIN);
        vector<char> seen(n,0);
        
        queue<int> q;
        for(int i=0;i<n;i++) {
            if(pending[i]==0)q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(seen[node]){ // was not leaf
                vector<int> &parents=map[node];
                long long baseVal=baseTime[node]+(maxi[node]-mini[node]) + maxi[node];
                for(int p:parents){
                    maxi[p]=max(maxi[p],baseVal);
                    mini[p]=min(mini[p],baseVal);
                    seen[p]=1;
                    pending[p]--;
                    if(pending[p]==0) q.push(p);
                }
            }
            else{ //original leaf
                //release
                vector<int> &parents=map[node];
                long long baseVal=baseTime[node];
                for(int p:parents){
                    
                    maxi[p]=max(maxi[p],baseVal);
                    mini[p]=min(mini[p],baseVal);
                    seen[p]=1;
                    pending[p]--;
                    if(pending[p]==0) q.push(p);
                }
            }
        }
        return maxi[0]+baseTime[0]+(maxi[0]-mini[0]);
        
    }
};
