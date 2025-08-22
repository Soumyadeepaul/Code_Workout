//https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/description/?envType=daily-question&envId=2025-08-22

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int rowmin=pow(10,9)+7;
        int colmin=pow(10,9)+7;   
        int rowmax=-pow(10,9)+7;
        int colmax=-pow(10,9)+7;   

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if (grid[i][j]==1){
                    if(rowmin>i){
                        rowmin=i;
                    }
                    if(rowmax<i){
                        rowmax=i;
                    }
                    if(colmin>j){
                        colmin=j;
                    }
                    if(colmax<j){
                        colmax=j;
                    }
                }
            }
        }
        return (colmax-colmin+1)*(rowmax-rowmin+1);
    }
};
