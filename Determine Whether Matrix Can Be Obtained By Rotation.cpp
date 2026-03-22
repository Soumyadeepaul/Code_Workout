//https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/description/?envType=daily-question&envId=2026-03-22


class Solution {
public:
    void rotate(vector<vector<int>>& mat){
        //transpose
        int end=1;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<end;j++){
                swap(mat[i][j],mat[j][i]);
            }
            end++;
        }
        for(int i=0;i<mat.size();i++){
            reverse(mat[i].begin(),mat[i].end());
        }
    }
    bool check(vector<vector<int>>& mat, vector<vector<int>>& target){
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat.size();j++){
                if(mat[i][j]!=target[i][j]) return false;
            }
        }
        return true;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {

        if (check(mat,target)) return true;
        
        rotate(mat);
        if (check(mat,target)) return true;

        rotate(mat);
        if (check(mat,target)) return true;

        rotate(mat);
        if (check(mat,target)) return true;

        return false;
    }
};
