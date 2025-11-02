//https://leetcode.com/problems/count-unguarded-cells-in-the-grid/description/?envType=daily-question&envId=2025-11-02

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
       vector<vector<int>> grid(m,vector<int> (n,0));
        for(vector<int> pair:walls){
        grid[pair[0]][pair[1]]=2;
       } 
       for(vector<int> pair:guards){
        grid[pair[0]][pair[1]]=9;
        //left
        int y=pair[1]-1;
        int x=pair[0];
        while(y>-1 && grid[x][y]!=2 && grid[x][y]!=9 && grid[x][y]!=4){
            grid[x][y]=4; // left right
            y--;
        }
        //right
        y=pair[1]+1;
        x=pair[0];
        while(y<n && grid[x][y]!=2 && grid[x][y]!=9 && grid[x][y]!=4){
            grid[x][y]=4; // left right
            y++;
        }

        //up
        y=pair[1];
        x=pair[0]-1;
        while(x>-1 && grid[x][y]!=2 && grid[x][y]!=9 && grid[x][y]!=5){
            grid[x][y]=5;//up down
            x--;
        }

        //down
        y=pair[1];
        x=pair[0]+1;
        while(x<m && grid[x][y]!=2 && grid[x][y]!=9 && grid[x][y]!=5){
            grid[x][y]=5; // up down
            x++;
        }
       }
       int count=0;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==0) count++;
        }
       }
       return count; 
    }
};
