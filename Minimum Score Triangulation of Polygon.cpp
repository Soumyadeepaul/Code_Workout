//https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/?envType=daily-question&envId=2025-09-29


class Solution {
public:
    
    int tri(vector<int>& values,int i,int j,int summ,vector<vector<int>> &dp){
        if(j-i+1<3) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=i+1;k<j;k++){
            summ=min(summ,values[i]*values[j]*values[k]+tri(values,i,k,summ,dp)+tri(values,k,j,summ,dp));
        }
        return dp[i][j]=summ;
    }
    int minScoreTriangulation(vector<int>& values) {
        int i=0;
        
        int l=values.size();
        int j=l-1;
        int summ=INT_MAX;
        vector<vector<int>> dp (51,vector<int>(51,-1));
        return tri(values,i,j,summ,dp);
    }
};
