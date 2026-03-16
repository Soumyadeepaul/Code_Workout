//https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/description/?envType=daily-question&envId=2026-03-16


class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<int> result;
        int rows=grid.size(),cols=grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                result.insert(grid[i][j]);
                for(int side=1;side<cols;side++){
                    if(i-side<0 || j-side<0 || i+side>=rows || j+side>=cols) break;
                    int summ=0;
                    for(int x=0;x<side;x++){
                        summ+=grid[i-side+x][j+x];
                        summ+=grid[i+side-x][j-x];
                        summ+=grid[i-x][j-side+x];
                        summ+=grid[i+x][j+side-x];
                    }
                    result.insert(summ);
                }
            }
        }
        vector<int> r;
        for(auto it=result.rbegin();it!=result.rend() && r.size()<3;++it){
            r.push_back(*it);
        }
        return r;
    }
};
