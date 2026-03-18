//https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/description/?envType=daily-question&envId=2026-03-18


class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int r=grid.size(),c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=1;j<c;j++){
                grid[i][j]+=grid[i][j-1];
            }
        }
        for(int j=0;j<c;j++){
            for(int i=1;i<r;i++){
                grid[i][j]+=grid[i-1][j];
            }
        }
        int count=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]<=k) count++;
                else break;
            }
        }
        return count;
    }
};
