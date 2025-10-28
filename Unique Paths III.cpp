//https://leetcode.com/problems/unique-paths-iii/description/


class Solution {
public:
    void dfs(vector<vector<int>>& grid, int &zeroCount,int x,int y,int &result,int count){
        // 4 direction
        if(x==-1 || y==-1 || x==grid.size() || y==grid[0].size()) return;
        if(grid[x][y]==2){
            if(zeroCount==count) result++;
            return;
        }
        else if(grid[x][y]==-1) return;
        else if(grid[x][y]==1) return;
        else{
            grid[x][y]=1;
            count++;
            dfs(grid,zeroCount,x-1,y,result,count);
            dfs(grid,zeroCount,x+1,y,result,count);
            dfs(grid,zeroCount,x,y-1,result,count);
            dfs(grid,zeroCount,x,y+1,result,count);
            grid[x][y]=0;
            count--;
        }

        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int zeroCount=1;
        pair<int,int> idx;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0) zeroCount++;
                else if(grid[i][j]==1) idx={i,j};
            }
        }
        grid[idx.first][idx.second]=0;
        int result=0;
        int count=0;
        dfs(grid,zeroCount,idx.first,idx.second,result,count);
        return result;
    }
};
