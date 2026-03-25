//https://leetcode.com/problems/shortest-bridge/description/


class Solution {
private:
    int gSize;
    vector<vector<int>> search;
    int result=1e9;
public:
    void helper(vector<vector<int>>& grid, int x,int y){
        if(x>=grid.size() || x<0 || y>=grid.size() || y<0) return;
        if(grid[x][y]==1) grid[x][y]=2;
        else return;
        search.push_back({x,y});
        helper(grid,x+1,y);
        helper(grid,x-1,y);

        helper(grid,x,y+1);
        helper(grid,x,y-1);
    }
    // void bfs(vector<vector<int>>& grid){
    //     queue<pair<vector<int>,int>> q;
    //     queue<pair<vector<int>,int>> emptyQ;

    //     for(vector<int> point:search){
    //         q.push({point,0});
    //         while(!q.empty()){
    //             auto p=q.front();
    //             q.pop();
    //             if(grid[p.first[0]][p.first[1]]==1){
    //                 result=min(result,p.second);
    //                 q=emptyQ;
    //                 break;
    //             }
    //             if(p.first[0]-1>-1 && grid[p.first[0]-1][p.first[1]]!=2) q.push({{p.first[0]-1,p.first[1]},p.second+1});
    //             if(p.first[0]+1< gSize  && grid[p.first[0]+1][p.first[1]]!=2) q.push({{p.first[0]+1,p.first[1]},p.second+1});
    //             if(p.first[1]-1>-1 && grid[p.first[0]][p.first[1]-1]!=2) q.push({{p.first[0],p.first[1]-1},p.second+1});
    //             if(p.first[1]+1< gSize && grid[p.first[0]][p.first[1]+1]!=2) q.push({{p.first[0],p.first[1]+1},p.second+1});

    //         }
    //     }
    // }

    int count=0;
    vector<vector<int>> q;
    void bfs(vector<vector<int>>& grid){
        while(true){
            for(vector<int> s : search){
                int x = s[0], y = s[1];

                vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

                for(auto d : dirs){
                    int nx = x + d.first;
                    int ny = y + d.second;

                    if(nx>=0 && ny>=0 && nx<gSize && ny<gSize){
                        if(grid[nx][ny] == 1){ // check neig first
                            result = count;
                            return;
                        }

                        //push only unvisited water
                        if(grid[nx][ny] == 0){
                            grid[nx][ny] = 2;   // visited
                            q.push_back({nx, ny});
                        }
                    }
                }
            }
            count++;
            search=q;
            q.clear();
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        gSize=grid.size();
        bool found=0;
        // 1st change 1 island to diff no.
        for(int i=0;i<gSize;i++){
            for(int j=0;j<gSize;j++){
                if(grid[i][j]==1){
                    helper(grid,i,j);
                    found=1;
                    break;
                }
            }
            if(found==1) break;
        }
        // for(int i=0;i<gSize;i++){
        //     for(int j=0;j<gSize;j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        bfs(grid);

        return result;

    }
};
