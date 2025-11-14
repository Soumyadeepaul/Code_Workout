//https://leetcode.com/problems/increment-submatrices-by-one/description/?envType=daily-question&envId=2025-11-14

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n,vector<int>(n,0));
        for(vector<int> q:queries){
            int row1=q[0],col1=q[1],row2=q[2],col2=q[3];
            for(int i=row1;i<=row2;i++){
                for(int j=col1;j<=col2;j++){
                    mat[i][j]++;
                }
            }
        }
        return mat;
    }
};
