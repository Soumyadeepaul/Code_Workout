//https://leetcode.com/problems/is-graph-bipartite/description/


class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> colour(n,-1);
        for(int i=0;i<n;i++){
            if(colour[i]!=-1) continue; //checked

            queue<int> q;
            q.push(i);
            colour[i]=0;
            while(!q.empty()){
                int node=q.front();
                q.pop();

                for(int j:graph[node]){
                    if(colour[j]==colour[node]) return false;
                    else if(colour[j]==-1){
                        colour[j]=1-colour[node];
                        q.push(j);
                    }
                }
            }
        }
        return true;
    }
};
