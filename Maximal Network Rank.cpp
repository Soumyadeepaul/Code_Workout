//https://leetcode.com/problems/maximal-network-rank/description/?envType=problem-list-v2&envId=graph


class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int,int> rank;
        unordered_map<int,unordered_set<int>> edges;
        for(auto r:roads){
            rank[r[0]]++;
            rank[r[1]]++;
            edges[r[0]].insert(r[1]);
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int total=rank[i]+rank[j];
                if(edges[i].count(j) || edges[j].count(i)) total--;
                maxi=max(maxi,total);
            }
        }
        return maxi;
    }
};
