//https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/description/?envType=daily-question&envId=2026-03-19


class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int r=grid.size(),c=grid[0].size();
        vector<vector<int>> dp(r,vector<int> (c,0));
        vector<vector<bool>> x(r,vector<bool> (c,0));

        for(int i=0;i<r;i++){
            int summ=0;
            bool found=false;
            for(int j=0;j<c;j++){
                if(grid[i][j]=='X'){
                    summ+=1;
                    found=true;
                }
                else if(grid[i][j]=='Y') summ-=1;
                dp[i][j]=summ;
                x[i][j]=found;
            }
        }
        for(int j=0;j<c;j++){
            for(int i=1;i<r;i++){
                dp[i][j]+=dp[i-1][j];
                x[i][j]=max(x[i][j],x[i-1][j]);
            }
        }

        // for(int i=0;i<r;i++){
        //     for(int j=0;j<c;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        // for(int i=0;i<r;i++){
        //     for(int j=0;j<c;j++){
        //         cout<<x[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int count=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(dp[i][j]==0 && x[i][j]==true) count++;
            }
        }

        return count;
    }
};
