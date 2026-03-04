//https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/?envType=daily-question&envId=2026-03-04

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> row(mat.size(),0);
        vector<int> col(mat[0].size(),0);
        for(int i=0;i<mat.size();i++){
            int summ=0;
            for(int j=0;j<mat[0].size();j++){
                summ+=mat[i][j];
            }
            row[i]=summ;
        }
        for(int i=0;i<mat[0].size();i++){
            int summ=0;
            for(int j=0;j<mat.size();j++){
                summ+=mat[j][i];
            }
            col[i]=summ;
        }

        int count=0;
        for(int i=0;i<mat.size();i++){
            if(row[i]!=1) continue;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1 && col[j]==1) count++;
            }
        }
        return count;
        
    }
};



