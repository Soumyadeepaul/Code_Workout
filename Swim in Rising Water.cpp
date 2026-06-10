//https://leetcode.com/problems/swim-in-rising-water/description/



class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; //val, maxVal, x,y
        pq.push({grid[0][0],grid[0][0],0,0});
        vector<pair<int,int>> dir={{0,1},{-1,0},{0,-1},{1,0}};
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(),-1));
        while(!pq.empty()){
            auto parent=pq.top();
            pq.pop();
            int cost=parent[1], x=parent[2], y=parent[3], val=parent[0];
            visited[x][y]=1;
            for(auto &[i,j]:dir){
                int nx=x+i, ny=y+j;
                if(nx>-1 && ny>-1 && ny<grid[0].size() && nx<grid.size() && visited[nx][ny]!=1){
                    if(nx==grid.size()-1 && ny==grid[0].size()-1) return max(cost,grid[nx][ny]);
                    pq.push({grid[nx][ny],max(cost,grid[nx][ny]),nx,ny});
                }
            }
        }
        return 0;
    }
};
