//https://leetcode.com/problems/surrounded-regions/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
private:
    void bfs(vector<vector<char>>& board, vector<vector<int>>& vis,
             int &i, int &j, int &m, int &n)
    {
        queue<pair<int,int>> q;
        vector<pair<int,int>> tempStore;

        q.push({i,j});
        vis[i][j] = 1;
        bool bounded = true;

        while(!q.empty()){
            auto p = q.front();
            int x = p.first, y = p.second;
            tempStore.push_back(p);
            q.pop();

            // boundary touch => not bounded
            if(x-1 < 0 || x+1 >= m || y-1 < 0 || y+1 >= n){
                bounded = false;
            }

            // explore neighbors
            if(x-1 >= 0 && board[x-1][y] == 'O' && vis[x-1][y] == 0){
                q.push({x-1, y});
                vis[x-1][y] = 1; //visited
            }
            if(y-1 >= 0 && board[x][y-1] == 'O' && vis[x][y-1] == 0){
                q.push({x, y-1});
                vis[x][y-1] = 1;
            }
            if(x+1 <  m && board[x+1][y] == 'O' && vis[x+1][y] == 0){
                q.push({x+1, y});
                vis[x+1][y] = 1;
            }
            if(y+1 <  n && board[x][y+1] == 'O' && vis[x][y+1] == 0){
                q.push({x, y+1});
                vis[x][y+1] = 1;
            }
        }

        // update board
        if(bounded == false){
            // revert to 'O'
            for(auto p: tempStore)
                board[p.first][p.second] = 'O';
        }
        else{
            for(auto p: tempStore)
                board[p.first][p.second] = 'X';
        }
    }

public:
    void solve(vector<vector<char>>& board) {

        int m = board.size(), n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0)); //checked

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'O' && vis[i][j] == 0){
                    bfs(board, vis, i, j, m, n);
                }
            }
        }
    }
};
