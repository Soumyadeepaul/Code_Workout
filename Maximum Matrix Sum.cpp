//https://leetcode.com/problems/maximum-matrix-sum/description/?envType=daily-question&envId=2026-01-05

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int count=0;
        int l=matrix.size();
        for(int i=0;i<l;i++){
            for(int j=0;j<l;j++){
                if(matrix[i][j]<0){
                    count++;
                }
            }
        }
        long long result=0;
        int mini=INT_MAX;
        int val=0;
        for(int i=0;i<l;i++){
            for(int j=0;j<l;j++){
                val=(matrix[i][j]<0)? -matrix[i][j]:matrix[i][j];
                result=(long long) result+val;
                mini=min(mini,val);
            }
        }
        if(count&1){
            result=(long long)result-2*mini;
        }
        return result;

    }
};
