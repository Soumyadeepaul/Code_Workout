//https://leetcode.com/problems/redundant-connection/description/?envType=problem-list-v2&envId=union-find



class Solution {
public:
    vector<int> parent;
    vector<int> level; // maintains the level of the tree
    int find(int x){
        if(parent[x]!=x) parent[x]=find(parent[x]);
        return parent[x];
    }   
    bool uni(int x,int y){
        int p1=find(x),p2=find(y);
        if(p1==p2) return false;  //same parent means.. already connected
        
        //lesser the value of level... higher in the tree
        if(level[p1]<=level[p2]){ // is p1 is top in the level.. it is the root
            parent[p2]=p1;
            level[p2]+=level[p1];
        }
        else{
            parent[p1]=p2; //if p2 is top in the level.. it is the root
            level[p1]+=level[p2];
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int nodes=edges.size();
        parent.resize(nodes+1);
        level.resize(nodes+1);
        iota(parent.begin(),parent.end(),0);
        for(auto &e:edges){
            if(!uni(e[0],e[1]))  return e;
        }
        return {};
    }
};
