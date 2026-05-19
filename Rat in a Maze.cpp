//https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1


class Solution {
  public:
    vector<string> result;
    vector<vector<int>> visited;
    void helper(int x,int y,vector<vector<int>>& maze, string tracker){
        if(x==(maze.size()-1) && y==(maze.size()-1)){
            result.push_back(tracker);
            return;
        }
        vector<pair<int,int>> directions={{1,0},{0,-1},{0,1},{-1,0}};
        int travel=0;
        for(auto &[nx,ny]: directions){
            int newX=x+nx, newY=y+ny;
            if(newX>-1 && newY>-1 && newX<maze.size() && newY<maze.size()){
                if(maze[newX][newY]==1 && visited[newX][newY]==-1){
                    visited[newX][newY]=1;
                    
                    if(travel==0) helper(newX, newY, maze, tracker+'D');
                    else if(travel==1) helper(newX, newY, maze, tracker+'L');
                    else if(travel==2) helper(newX, newY, maze, tracker+'R');
                    else if(travel==3) helper(newX, newY, maze, tracker+'U');
                    
                    visited[newX][newY]=-1;
                }
            }
            travel++;
        }
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        visited.resize(maze.size(),vector<int> (maze.size(),-1));
        visited[0][0]=1;
        helper(0,0,maze,"");
        return result;
        
    }
};
