//https://leetcode.com/problems/shortest-path-in-binary-matrix/description/



class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[n-1][n-1]==1 || grid[0][0]==1) return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<vector<int>> visited(n, vector<int> (n,-1));
        vector<pair<int,int>> direction={{-1,-1}, {-1,0},{-1,1}, {0,-1},{0,1}, {1,-1},{1,0},{1,1}};
        visited[0][0]=1;
        while(!q.empty()){
            auto top=q.front();
            int x=top.first, y=top.second;
            q.pop();
            for(auto &[nx,ny]: direction){
                int newX=x+nx, newY=y+ny;
                if(newX>-1 && newX<n && newY>-1 && newY<n){
                    if(grid[newX][newY]==1) continue;
                    if(visited[newX][newY]==-1) {
                        visited[newX][newY]=visited[x][y]+1;
                        q.push({newX,newY});
                    }
                }
            }
        }
        return visited[n-1][n-1];
    }
};
