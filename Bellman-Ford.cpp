//https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1


// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V,1e8);
        dist[src]=0;
        
        for(int i=0;i<V-1;i++){
            for(auto &e:edges){
                int u=e[0],v=e[1],wt=e[2];
                
                if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
                    dist[v]=dist[u]+wt;
                }
            }
        }
        
        //Nth to detect negetive cycle
        for(int i=0;i<1;i++){
            for(auto &e:edges){
                int u=e[0],v=e[1],wt=e[2];
                if(dist[u]!=1e8 && dist[u]+wt<dist[v]) return {-1};
            }
        }
        return dist;
    }
};
