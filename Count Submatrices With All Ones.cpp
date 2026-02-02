//https://leetcode.com/problems/count-submatrices-with-all-ones/description/


class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        vector<vector<int>> consequtive(mat.size(),vector<int> (mat[0].size(),0));

        for(int i=0;i<mat.size();i++){
            int count=0;
            for(int j=mat[0].size()-1;j>-1;j--){
                if(mat[i][j]==1) count++;
                else count=0;

                consequtive[i][j]=count;
            }
        }
        
        int result=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                int count=INT_MAX;
                for(int row=i;row<mat.size();row++){
                    count=min(count,consequtive[row][j]);
                    result+=count;
                }
            }
        }
        return result;

    }
};
