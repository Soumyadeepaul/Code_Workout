//https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/description/


class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(parent[x]!=x) parent[x]=find(parent[x]);
        return parent[x];
    }
    void uni(int x, int y){
        int px=find(x), py= find(y);
        if(px==py) return;
        else if(rank[px]>rank[py]){
            parent[py]=px;
        }
        else if(rank[px]<rank[py]){
            parent[px]=py;
        }
        else{
            parent[py]=px;
            rank[px]++;
        }
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        rank.resize(n,0);
        iota(parent.begin(),parent.end(),0);

        for(auto e:edges){
            uni(e[0],e[1]);
        }

        unordered_map<int,int> map; //parent: group of edge's  &

        for(auto e:edges){
            int px=find(e[0]), py=find(e[1]);
            if(px==py) {
                if(map.count(px)) map[px]&=e[2];
                else map[px]=e[2];
            }
        }

        vector<int> result;
        for(auto e:query){
            int px=find(e[0]), py=find(e[1]);
            if(px==py) result.push_back(map[px]);
            else result.push_back(-1);
        }
        return result;
    }
};
