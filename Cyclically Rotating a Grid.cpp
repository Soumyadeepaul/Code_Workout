//https://leetcode.com/problems/cyclically-rotating-a-grid/?envType=daily-question&envId=2026-05-09

class Solution {
public:
    void helper(vector<vector<int>>& grid, int k, int row, int col, int i, int j){
        vector<int> store;
        for(int y=j;y<col;y++){
            store.emplace_back(grid[i][y]);
        }
        store.pop_back();
        for(int x=i;x<row;x++){
            store.emplace_back(grid[x][col-1]);
        }
        store.pop_back();
        for(int y=col-1;y>=j;y--){
            store.emplace_back(grid[row-1][y]);
        }
        store.pop_back();
        for(int x=row-1;x>=i;x--){
            store.emplace_back(grid[x][j]);
        }
        store.pop_back();
        int length=store.size();
        int newK=k%length;
        //rotate;
        store.insert(store.end(),store.begin(),store.begin()+newK);


        int idx=newK;
        for(int y=j;y<col-1;y++){
            grid[i][y]=store[idx++];
        }
        for(int x=i;x<row-1;x++){

            grid[x][col-1]=store[idx++];
        }
        for(int y=col-1;y>=j+1;y--){
            grid[row-1][y]=store[idx++];
        }
        for(int x=row-1;x>=i+1;x--){
            grid[x][j]=store[idx++];
        }

    }
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int r=grid.size(),c=grid[0].size();
        for(int i=0;i<min(r/2,c/2);i++){
            helper(grid,k,r-i,c-i,i,i);
        }
        return grid;
    }
};
