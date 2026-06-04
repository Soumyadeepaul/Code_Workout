//https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/


class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(parent[x]==-1) return -1;
        if(parent[x]!=x) return parent[x]=find(parent[x]);
        return parent[x];
    }
    void uni(int a, int b){
        int pa=find(a),pb=find(b);
        if(pa==pb) return;
        
        if(rank[pa]<rank[pb]){
            parent[pa]=pb;
        }
        else if(rank[pa]>rank[pb]){
            parent[pb]=pa;
        }
        else{
            parent[pb]=pa;
            rank[pa]++;
        }

    }
    int removeStones(vector<vector<int>>& stones) {
        int OFFSET = 10001;// so that it doesnt overlap

        parent.resize(20002);
        rank.resize(20002, 0);
       
       for(auto s:stones){
            parent[s[0]]=s[0];
            parent[s[1]+OFFSET]=s[1]+OFFSET;
        }
        
        for(auto p:stones){
            uni(p[0],p[1]+OFFSET);
        }
        unordered_map<int, int> map; // parent..counts
        for(auto p:stones){
            map[find(p[0])]++; //number of stones in each component
        }
        int result=0;
        for(auto p:map) {
            result+=p.second-1; //in each component we cant remove 1 stone
        }

        return result;
    }
};
