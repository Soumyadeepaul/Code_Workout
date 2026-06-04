//https://leetcode.com/problems/minimum-falling-path-sum-ii/description/


class Solution {
public:
    vector<int> mini1, mini2;
    void minis(vector<int> rows){
        mini1={INT_MAX,-1,-1};
        mini2={INT_MAX,-1,-1};
        for(int i=0;i<rows.size();i++){
            if(mini1[0]>rows[i]){
                mini2=mini1;
                mini1={rows[i],i};
            }
            else if(mini2[0]>rows[i]) mini2={rows[i],i};
        }
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int rows=grid.size(), cols=grid[0].size();
        minis(grid[0]);
        for(int i=1;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(mini1[1]==j) grid[i][j]+=mini2[0];
                else grid[i][j]+=mini1[0];
            }
            minis(grid[i]);
        }
        return *min_element(grid[rows-1].begin(),grid[rows-1].end());
    }
};
