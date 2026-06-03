//https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(parent[x]!=x) parent[x]=find(parent[x]);
        return parent[x];
    }
    void uni(int u, int v){
        int pu=find(u), pv=find(v);
        if(pu==pv) return;

        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
        return;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges=connections.size();
        if(n-1>edges) return -1;
        int result=0;
        //find connected components
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;

        for(auto e:connections) {
            uni(e[0],e[1]);
        }

        unordered_set<int> roots;
        for(int i:parent) roots.insert(find(i));


        return roots.size()-1;
    }
};
