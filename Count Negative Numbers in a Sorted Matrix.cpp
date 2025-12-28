//https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/?envType=daily-question&envId=2025-12-28

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        for(vector<int> g:grid){
            for(int i=g.size()-1;i>-1;i--){
                if(g[i]<0) count++;
                else break;
            }
        }
        return count;
    }
};
