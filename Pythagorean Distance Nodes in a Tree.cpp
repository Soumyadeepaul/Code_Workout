//https://leetcode.com/contest/weekly-contest-486/problems/pythagorean-distance-nodes-in-a-tree/description/


class Solution {
public:
    vector<int> bfs( int &node, unordered_map<int, vector<int>> & edg, int &n){
        // lets find x;
        //bfs
        queue<pair<int,int>> q;  //{node,distance}
        q.push({node,0});

        vector<int> dist(n,-1);
        dist[node]=0;
        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            vector<int> e=edg[p.first];
            for(int i:e){
                if(dist[i]==-1){
                    dist[i]=p.second+1;
                    q.push({i,p.second+1});
                }
            }
            
        }

        return dist;
        
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        unordered_map<int, vector<int>> edg;
        for(vector<int> e:edges){
            edg[e[0]].push_back(e[1]);
            edg[e[1]].push_back(e[0]);
            
        }

        vector<int> dx=bfs(x,edg,n);
        vector<int> dy=bfs(y,edg,n);
        vector<int> dz=bfs(z,edg,n);
        
        int count=0;
        for(int i=0;i<n;i++){
            if(dx[i]==-1 || dy[i]==-1 || dz[i]==-1) continue;
            vector<int> abc={dx[i],dy[i],dz[i]};
            sort(abc.begin(),abc.end());
    
            if(pow(abc[0],2)+pow(abc[1],2)==pow(abc[2],2)) count++;
        }

        return count;
    }
};
