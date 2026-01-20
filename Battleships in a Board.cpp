//https://leetcode.com/problems/battleships-in-a-board/description/?envType=problem-list-v2&envId=matrix


class Solution {
public:
    int count=0;
    // void helper(vector<vector<char>>& board, stack<pair<int,int>> &st){
    //     while(!st.empty()){
    //         pair<int,int> p=st.top();
    //         st.pop();
    //         int i=p.first,j=p.second;
    //         if(board[i][j]=='X'){
    //             board[i][j]='.';
    //             if(i+1<board.size())    st.push({i+1,j});
    //             if(j+1<board[0].size())  st.push({i,j+1});
    //         }
    //     }
    // }
    void helper(vector<vector<char>>& board, int i, int j){
        if(board[i][j]=='X'){
            board[i][j]='.';
            if(i+1<board.size())    helper(board,i+1,j);
            if(j+1<board[0].size())  helper(board,i,j+1);
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        stack<pair<int,int>> st;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='X'){
                    st.push({i,j});
                    helper(board,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
