//https://leetcode.com/problems/island-perimeter/description/?envType=problem-list-v2&envId=array



class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int count;
        int r=grid.size();
        int c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    queue<vector<int>> q;
                    q.push({i,j});
                    count=0;
                    while(!q.empty()){
                        vector<int> idxs=q.front();
                        q.pop();
                        int x=idxs[0];
                        int y=idxs[1];
                        grid[x][y]=-1;
                        cout<<x<<" "<<y<<endl;
                        if(x-1>-1){
                            if(grid[x-1][y]==0)
                                count++;
                            else if(grid[x-1][y]==1){
                                grid[x-1][y]=-1;
                                q.push({x-1,y});
                            }
                        }
                        if(y-1>-1){
                            if(grid[x][y-1]==0)
                                count++;
                            else if(grid[x][y-1]==1){
                                grid[x][y-1]=-1;
                                q.push({x,y-1});
                            }
                        }
                        if(x+1<r ){
                            if(grid[x+1][y]==0)
                                count++;
                            else if(grid[x+1][y]==1){
                                grid[x+1][y]=-1;
                                q.push({x+1,y});
                            }
                        }
                        if(y+1<c ){
                            if(grid[x][y+1]==0)
                                count++;
                            else if(grid[x][y+1]==1){
                                grid[x][y+1]=-1;
                                q.push({x,y+1});
                            }
                        }
                        if(x-1==-1) count++;
                        if(y-1==-1) count++;
                        if(x+1==r) count++;
                        if(y+1==c) count++;

                    }

                }

            }
        }
        return count;
    }
};
