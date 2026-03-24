//https://leetcode.com/problems/construct-product-matrix/description/?envType=daily-question&envId=2026-03-24


class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        vector<vector<int>> pref(rows,vector<int> (cols,1));
        vector<vector<int>> suff(rows,vector<int> (cols,1));
        long long mul=1, prev=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(i==0 && j==0){
                    prev=grid[i][j];
                    continue;
                }
                mul=(1ll*mul*prev)%12345;
                pref[i][j]=mul;
                prev=grid[i][j];
            }
        }

        mul=1, prev=0;
        for(int i=rows-1;i>-1;i--){
            for(int j=cols-1;j>-1;j--){
                if(i==rows-1 && j==cols-1){
                    prev=grid[i][j];
                    continue;
                }
                mul=(1ll*mul*prev)%12345;
                suff[i][j]=mul;
                prev=grid[i][j];
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                grid[i][j]=(pref[i][j]*suff[i][j])%12345;
            }
        }

        return grid;
    }
};
