//https://leetcode.com/problems/transpose-matrix/description/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> mat;
        vector<int> store;
        for(int col=0;col<matrix[0].size();col++){
            store.clear();
            for(int row=0;row<matrix.size();row++){
                store.push_back(matrix[row][col]);
            }
            mat.push_back(store);
        }
        return mat;
    }
};
