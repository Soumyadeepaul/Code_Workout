//https://leetcode.com/problems/find-a-safe-walk-through-a-grid/description/?envType=daily-question&envId=2026-07-02


class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({grid[0][0],0,0});
        int r=grid.size(),c=grid[0].size();
        vector<vector<int>> visited(r,vector<int>(c,0));
        vector<pair<int,int>> dirs={{-1,0},{0,-1},{1,0},{0,1}};
        visited[0][0]=1;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int cost=top[0],i=top[1],j=top[2];
            if(i==r-1 && j==c-1){
                if(cost<health) return true;
                break;
            }
            for(auto &[x,y]:dirs){
                int ni=i+x,nj=y+j;
                if (ni<0 || nj<0 || ni>=r || nj>=c || visited[ni][nj]==1) continue;
                visited[ni][nj]=1;
                pq.push({cost+grid[ni][nj],ni,nj});
            }
        }
        return false;
    }
};
