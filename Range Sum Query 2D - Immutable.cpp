//https://leetcode.com/problems/range-sum-query-2d-immutable/description/?envType=problem-list-v2&envId=prefix-sum


class NumMatrix {
private:
    unordered_map<int,unordered_map<int,int>> store;
    int l1,l2;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        l1 = matrix.size();
        l2 = matrix[0].size();

        for(int i=0;i<l1;i++){
            for(int j=0;j<l2;j++){
                int summ=matrix[i][j];
                if(i-1>-1){
                    summ+=store[i-1][j];
                }
                if(j-1>-1){
                    summ+=store[i][j-1];
                }
                if(j-1>-1 && i-1>-1){
                    summ-=store[i-1][j-1];
                }
                store[i][j]=summ;
                
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        //total - (up U left)+ diagonal
        int total=store[row2][col2];
        int diagonal=0;
        if(row1-1>-1 && col1-1>-1){
            diagonal=store[row1-1][col1-1];
        }
        int left=0;
        if(col1-1>-1){
            left=store[row2][col1-1];
        }
        int up=0;
        if(row1-1>-1){
            up=store[row1-1][col2];
        } 
        return total- (up+left) + diagonal;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
