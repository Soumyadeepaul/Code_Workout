//https://leetcode.com/problems/diagonal-traverse/


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
       //[0,0] ->0
       //[0,1],[1,0]->1
       //[0,2],[1,1],[2,0]->2
       unordered_map<int,vector<int>> map;
       int m=mat.size();
       int n=mat[0].size();
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            map[i+j].push_back(mat[i][j]);
        }
       }
       vector<int> result;
       for(int s=0;s<m-1+n;s++){
        if(s&1){//odd
            for(int j: map[s]){
                result.push_back(j);
            }
        }
        else{
            reverse(map[s].begin(),map[s].end());
            for(int j: map[s]){
                result.push_back(j);
            }
        }
        
       }
       return result;
    }
};
