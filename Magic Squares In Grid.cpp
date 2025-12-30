//https://leetcode.com/problems/magic-squares-in-grid/description/?envType=daily-question&envId=2025-12-30


class Solution {
public:
    bool checker(vector<vector<int>>& grid, int &i, int &j){
        if(grid[i+1][j+1] != 5) return false;

        vector<int> check(9, 0);

        // rows
        for(int r = 0; r < 3; r++){
            int sum = 0;
            for(int c = 0; c < 3; c++){
                int val = grid[i+r][j+c];
                if(val < 1 || val > 9) return false;
                if(check[val-1]++) return false;
                sum += val;
            }
            if(sum != 15) return false;
        }

        // columns
        for(int c = 0; c < 3; c++){
            int sum = 0;
            for(int r = 0; r < 3; r++){
                sum += grid[i+r][j+c];
            }
            if(sum != 15) return false;
        }

        // diagonals
        if(grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2] != 15) return false;
        if(grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j] != 15) return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if(grid.size()<3 || grid[0].size()<3) return 0;
        int count=0;
        for(int i=0;i<grid.size()-2;i++){
            for(int j=0;j<grid[0].size()-2;j++){
                count+= (checker(grid,i,j)) ? 1 : 0;
            }
        }
        return count;
    }
};
