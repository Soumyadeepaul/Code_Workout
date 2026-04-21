//https://leetcode.com/problems/max-area-of-island/description/?envType=problem-list-v2&envId=union-find


class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j, int &r,int &c){
        grid[i][j]=0;
        int val=1;
        if(i-1!=-1 && grid[i-1][j]==1) val+=dfs(grid,i-1,j,r,c);
        if(j-1!=-1 && grid[i][j-1]==1) val+=dfs(grid,i,j-1,r,c);
        if(i+1!=r && grid[i+1][j]==1) val+=dfs(grid,i+1,j,r,c);
        if(j+1!=c && grid[i][j+1]==1) val+=dfs(grid,i,j+1,r,c);

        return val;
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result=0;
        int r=grid.size(),c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    result=max(result,dfs(grid,i,j,r,c));
                }
            }
        }
        return result;
    }
};
