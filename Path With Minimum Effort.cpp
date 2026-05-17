//https://leetcode.com/problems/path-with-minimum-effort/description/


class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows=heights.size(),cols=heights[0].size();
        vector<vector<int>> visited (rows,vector<int> (cols,INT_MAX));
        vector<pair<int,int>> directions={{-1,0},{0,-1},{0,1},{1,0}};
        queue<
            vector<int>
        > q;
        q.push({0,0,0});
        visited[0][0]=0;
        int result=INT_MAX;
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            int x=top[1],y=top[2], count=top[0];
            if(x==rows-1 && y==cols-1){
                result=min(result,count);
                continue;
            }
            
            for(auto &[nx,ny]:directions){
                int newX=x+nx, newY=y+ny;
                if(newX>-1 && newY>-1 && newX<rows && newY<cols ){
                    int newCount=max(count,abs(heights[x][y]-heights[newX][newY]));
                    if(newCount>=visited[newX][newY]) continue;
                    visited[newX][newY]=newCount;
                    q.push({newCount,newX,newY});
                }
            }
        }
        return result;
    }
};
