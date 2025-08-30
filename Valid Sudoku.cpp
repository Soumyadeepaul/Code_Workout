//https://leetcode.com/problems/valid-sudoku/description/?envType=daily-question&envId=2025-08-30


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // just validate the filled cells
        for(int i=0;i<board.size()-2;i=i+3){
            for(int j=0;j<board[0].size()-2;j=j+3){

                unordered_set<char> numbers;
                char x;
                for(int a=48;a<48+10;a++){
                    x=a;
                    numbers.insert(x);
                }
                //inner matrix
                for(int x=i;x<i+3;x++){
                    for(int y=j;y<j+3;y++){
                        //check for box
                        for(auto i:numbers){
                            cout<<i<<" ";
                        }
                        cout<<endl;
                        if(board[x][y]=='.'){
                            continue;
                        }
                        else if(numbers.find(board[x][y])!=numbers.end()){
                            numbers.erase(board[x][y]);
                        }
                        else{
                            cout<<x<<" "<<y<<endl;
                            return false;
                        }
                    }
                }
                
                
                //check row & col
                for(int x=i;x<i+3;x++){
                    for(int y=j;y<j+3;y++){
                        if(board[x][y]=='.'){
                            continue;
                        }
                        //col
                        for(int b=y+1;b<board[0].size();b++){
                            if(board[x][y]==board[x][b]){
                                return false;
                            }
                        }
                        //row
                        for(int a=x+1;a<board.size();a++){
                            if(board[x][y]==board[a][y]){
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
