//https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/description/?envType=daily-question&envId=2026-01-19



class Solution {
public:
    bool check(vector<vector<int>>& mat,int &threshold, int &row, int &col, int &size){
        int total=0;
        
        for(int i=row;i<row+size;i++){
            for(int j=col;j<col+size;j++){
                total+=mat[i][j];
            }
        }
        return total<=threshold;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int result=0, l1=mat.size(),l2=mat[0].size();
        for(int i=0;i<l1;i++){
            for(int j=0;j<l2;j++){
                for(int k=1;i+k<=l1 && j+k<=l2;k++){
                    if(check(mat,threshold,i,j,k)) result=max(result,k);
                    else break;
                }
            }
        }
        return result;
    }
};
