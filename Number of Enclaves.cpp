//https://leetcode.com/problems/number-of-enclaves/description/



class Solution {
public:
    int result=0;
    void helper(vector<vector<int>>& grid, int i, int j){

        vector<pair<int,int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
        queue<vector<int>> q;
        q.push({i,j,0});
        grid[i][j]=0;
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            int x=front[0], y=front[1];
            for(auto &[nx,ny]:dir){
                int newx=x+nx, newy=y+ny;
                if(newx<0 || newy<0 || newx>grid.size()-1 || newy>grid[0].size()-1) {
                    continue;
                }
                if(grid[newx][newy]==1) {
                    grid[newx][newy]=0;
                    q.push({newx,newy}); 
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        for(int i=0;i<rows;i++){
            if(grid[i][0]==1) helper(grid,i,0);
            if(grid[i][cols-1]==1) helper(grid,i,cols-1);
        }
        for(int j=0;j<cols;j++){
            if(grid[0][j]==1) helper(grid,0,j);
            if(grid[rows-1][j]==1) helper(grid,rows-1,j);
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1) result++;
            }
        }
        return result;
    }
};
