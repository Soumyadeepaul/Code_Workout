//https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/description/?envType=daily-question&envId=2025-11-26


class Solution {
public:

    //TLE
    // void dfs(vector<vector<int>>& grid,int k,int value,int i,int j, int &r,int &c, int &result){
    //     if(i==r || j==c) return;
    //     if(i==r-1 && j==c-1){
    //         value+=grid[i][j];
    //         if(value%k==0) result++;
    //         return;
    //     }

    //     dfs(grid,k,(value+grid[i][j])%k,i,j+1,r,c,result);
    //     dfs(grid,k,(value+grid[i][j])%k,i+1,j,r,c,result);
    //     return;
    // }
    // int numberOfPaths(vector<vector<int>>& grid, int k) {
    //     int r=grid.size(),c=grid[0].size(), result=0;
    //     dfs(grid,k,0,0,0,r,c,result);
    //     return result;
    // }


    int mod= pow(10,9)+7;
    void bottomUp(vector<vector<int>>& grid,int k,int i,int j, int &r,int &c,vector<vector<vector<int>>> &freq){
    for(int x=i;x>=0;x--){
        for(int y=j;y>=0;y--){
            
            if(x==r-1 && y==c-1){
                freq[x][y][grid[x][y] % k] = 1;  // the bottom corner will set its remender at its value%k location in freq
                continue;
            }

            for(int a=0;a<k;a++){
                if(x+1<r){
                    int newRem = (a + grid[x][y]) % k;  // remender + value..... rembemder is index
                    freq[x][y][newRem] += freq[x+1][y][a] % mod;
                }
                if(y+1<c){
                    int newRem = (a + grid[x][y]) % k;
                    freq[x][y][newRem] += freq[x][y+1][a] % mod;
                }
            }
        }
    }
}

int numberOfPaths(vector<vector<int>>& grid, int k) {
    int r=grid.size(), c=grid[0].size();
    // the inner most vector stores the freq of each remainder possible
    vector<vector<vector<int>>> freq(r, vector<vector<int>>(c, vector<int>(k,0)));

    bottomUp(grid, k, r-1, c-1, r, c, freq);
    return freq[0][0][0]% mod;
}

};
