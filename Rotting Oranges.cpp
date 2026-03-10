//https://leetcode.com/problems/rotting-oranges/?envType=problem-list-v2&envId=interview-instance-ii

class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> time(grid.size(),vector<int> (grid[0].size(),1e9));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    time[i][j]=0;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty()){
                        auto node=q.front();
                        q.pop();
                        int x=node.first, y=node.second;
                        if(x-1>-1 && grid[x-1][y]==1){
                            if(time[x-1][y]>time[x][y]+1){
                                q.push({x-1,y});
                                time[x-1][y]=time[x][y]+1;
                            }
                        }
                        if(y-1>-1 && grid[x][y-1]==1){
                            if(time[x][y-1]>time[x][y]+1){
                                q.push({x,y-1});
                                time[x][y-1]=time[x][y]+1;
                            }
                        }
                        if(x+1<grid.size() && grid[x+1][y]==1 && time[x+1][y]>time[x][y]+1){
                            q.push({x+1,y});
                            time[x+1][y]=time[x][y]+1;
                        }
                        if(y+1<grid[0].size() && grid[x][y+1]==1 && time[x][y+1]>time[x][y]+1){
                            q.push({x,y+1});
                            time[x][y+1]=time[x][y]+1;
                        }
                    }
                }
            }
        }
        int result=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && time[i][j]==1e9) return -1;
                if(grid[i][j]==1 || grid[i][j]==2) result=max(result,time[i][j]);
            }
        }
        return result;
    }
};
