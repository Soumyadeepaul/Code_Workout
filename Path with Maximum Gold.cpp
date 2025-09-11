//https://leetcode.com/problems/path-with-maximum-gold/description/

class Solution {
public:
    int dfs(vector<vector<int>> &grid,int i,int j,int summ,int &row,int &col){
        if(i<0) return 0;
        if(j<0) return 0;
        if(i>row-1) return 0;
        if(j>col-1) return 0;
        if(grid[i][j]==0) return 0;
        int val=grid[i][j];
        grid[i][j]=0;
        int left=0,right=0,up=0,down=0;
        if(i-1!=-1 && grid[i-1][j]!=0){
            up=dfs(grid,i-1,j,summ,row,col);
        }
        if(j-1!=-1 && grid[i][j-1]!=0){
            left=dfs(grid,i,j-1,summ,row,col);
        }
        if(i+1!=row && grid[i+1][j]!=0){
            down=dfs(grid,i+1,j,summ,row,col);
        }
        if(j+1!=col && grid[i][j+1]!=0){
            right=dfs(grid,i,j+1,summ,row,col);
        }
        grid[i][j]=val; //backtracking 
        summ=val+max(up,max(right,max(left,down)));
        return summ;

    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int result=0;
        int summ;
        for(int i=0;i<row;i++){
            summ=0;
            for(int j=0;j<col;j++){
                result=max(result,dfs(grid,i,j,summ,row,col));
            }
        }
        
        return result;

    }
};
