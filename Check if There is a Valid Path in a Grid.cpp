//https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/description/?envType=daily-question&envId=2026-04-27


class Solution {
public:

    bool nextCell(vector<vector<int>>& grid,int i,int j,int &r,int &c, int parentI, int parentJ, vector<vector<bool>>& visited){
        
        if(i==r-1 && j==c-1) return true;
        if(visited[i][j]==true) return false;
        visited[i][j]=true;
        if(grid[i][j]==1){
            if(j-1!=parentJ) {
                if(j-1!=-1 && (grid[i][j-1]==1 || grid[i][j-1]==4 || grid[i][j-1]==6) && nextCell(grid,i,j-1,r,c,i,j,visited)) return true;
            }
             if(j+1!=parentJ) {if(j+1!=c && (grid[i][j+1]==1 || grid[i][j+1]==3 || grid[i][j+1]==5) &&nextCell(grid,i,j+1,r,c,i,j,visited)) return true;}
        }
        else if(grid[i][j]==2){
            if(i-1!=parentI) {if(i-1!=-1 && (grid[i-1][j]==2 || grid[i-1][j]==3 || grid[i-1][j]==4) && nextCell(grid,i-1,j,r,c,i,j,visited)) return true;}
             if(i+1!=parentI) {if(i+1!=r && (grid[i+1][j]==2 || grid[i+1][j]==5 || grid[i+1][j]==6) && nextCell(grid,i+1,j,r,c,i,j,visited)) return true;}
        }
        else if(grid[i][j]==3){
            if(j-1!=parentJ) {if(j-1!=-1 && (grid[i][j-1]==1 || grid[i][j-1]==4 || grid[i][j-1]==6) && nextCell(grid,i,j-1,r,c,i,j,visited)) return true;}
             if(i+1!=parentI) {if(i+1!=r && (grid[i+1][j]==2 || grid[i+1][j]==5 || grid[i+1][j]==6) && nextCell(grid,i+1,j,r,c,i,j,visited)) return true;}
        }
        else if(grid[i][j]==4){
            if(j+1!=parentJ) {if(j+1!=c && (grid[i][j+1]==1 || grid[i][j+1]==5 || grid[i][j+1]==3) &&nextCell(grid,i,j+1,r,c,i,j,visited)) return true;}
             if(i+1!=parentI) {if(i+1!=r && (grid[i+1][j]==2 || grid[i+1][j]==5 || grid[i+1][j]==6) && nextCell(grid,i+1,j,r,c,i,j,visited)) return true;}
        }
        else if(grid[i][j]==5){
            if(j-1!=parentJ) {if(j-1!=-1 && (grid[i][j-1]==1 || grid[i][j-1]==4 || grid[i][j-1]==6) &&nextCell(grid,i,j-1,r,c,i,j,visited)) return true;}
             if(i-1!=parentI) {if(i-1!=-1 && (grid[i-1][j]==2 || grid[i-1][j]==3 || grid[i-1][j]==4) && nextCell(grid,i-1,j,r,c,i,j,visited)) return true;}
        }
        else if(grid[i][j]==6){
            if(j+1!=parentJ) {if(j+1!=c && (grid[i][j+1]==1 || grid[i][j+1]==5 || grid[i][j+1]==3) &&nextCell(grid,i,j+1,r,c,i,j,visited)) return true;}
             if(i-1!=parentI) {if(i-1!=-1 && (grid[i-1][j]==2 || grid[i-1][j]==3 || grid[i-1][j]==4) && nextCell(grid,i-1,j,r,c,i,j,visited)) return true;}
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        vector<vector<bool>> visited(r,vector<bool> (c,false));
        return nextCell(grid,0,0,r,c,-1,-1,visited);
    }
};
