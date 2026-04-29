//https://leetcode.com/problems/minesweeper/description/


class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int sizeR=board.size(),sizeC=board[0].size();
        vector<pair<int,int>> sides={{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
        stack<vector<int>> bucket;
        bucket.push(click);
        while(!bucket.empty()){
            click[0]=bucket.top()[0];
            click[1]=bucket.top()[1];
            bucket.pop();
            if(board[click[0]][click[1]]=='M') {
                board[click[0]][click[1]]='X';
                break;
            }
            else if(board[click[0]][click[1]]=='E'){
                int mines=0;
                vector<vector<int>> store;
                for(auto &[x,y]:sides){
                    int nx=click[0]+x, ny=click[1]+y;
                    if(nx>-1 && ny>-1 && nx<sizeR && ny<sizeC){
                        if(board[nx][ny]=='M') mines++;
                        else{
                            store.push_back({nx,ny});
                        }
                    }
                }
                char c='0'+mines;
                if(mines==0){
                    board[click[0]][click[1]]='B';
                    for(auto s:store) bucket.push(s);
                }
                else board[click[0]][click[1]]=c;
            }
        }
        return board;
    }
};
