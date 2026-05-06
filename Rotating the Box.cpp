//https://leetcode.com/problems/rotating-the-box/description/?envType=daily-question&envId=2026-05-06


class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int r=boxGrid.size(),c=boxGrid[0].size();
        vector<vector<char>> result(c,vector<char>(r));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                result[j][r - 1 - i] = boxGrid[i][j];
            }
        }
        queue<pair<int,int>> clear;
        queue<pair<int,int>> q;
        for(int j=r-1;j>-1;j--){
            q=clear;
            for(int i=c-1;i>-1;i--){
                if(result[i][j]=='.'){
                    q.push({i,j});
                }
                else if(result[i][j]=='*') q=clear;
                else{
                    if(!q.empty()){
                        auto [x,y]=q.front();
                        q.pop();
                        result[x][y]='#';
                        result[i][j]='.';
                        q.push({i,j});
                    }
                }
            }
        }
        return result;
    }
};
