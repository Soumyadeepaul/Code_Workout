//https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/


class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(2,vector<int>(matrix[0].size()+1,0));
        int idx=1;
        int count=0;
        for(int i=0;i<matrix[0].size();i++){
            dp[0][i+1]=matrix[0][i];
            if(matrix[0][i]==1) count++;
        }
        for(;idx<matrix.size();idx++){
            for(int i=1;i<dp[0].size();i++){
                if(matrix[idx][i-1]==0){
                    dp[1][i]=0;
                }
                else{
                    dp[1][i]=min(dp[0][i],min(dp[1][i-1],dp[0][i-1]))+1;
                    count+=dp[1][i];
                } 
            }
            dp[0]=dp[1];
        } 
        return count;
    }
};
