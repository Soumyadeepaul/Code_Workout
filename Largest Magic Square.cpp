//https://leetcode.com/problems/largest-magic-square/description/?envType=daily-question&envId=2026-01-18


class Solution {
public:
    bool check(vector<vector<int>>& grid, int row, int col, int size) {
        int prevSum = -1;

        // rows
        for (int i = 0; i < size; i++) {
            int rowSum = 0;
            for (int j = 0; j < size; j++) {
                rowSum += grid[row + i][col + j];
            }
            if (prevSum == -1) prevSum = rowSum;
            else if (rowSum != prevSum) return false;
        }

        // columns
        for (int j = 0; j < size; j++) {
            int colSum = 0;
            for (int i = 0; i < size; i++) {
                colSum += grid[row + i][col + j];
            }
            if (colSum != prevSum) return false;
        }

        // diagonals
        int fDia = 0, rDia = 0;
        for (int d = 0; d < size; d++) {
            fDia += grid[row + d][col + d];
            rDia += grid[row + d][col + size - 1 - d];
        }

        return fDia == prevSum && rDia == prevSum;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int result=1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 2; i + k <= n && j + k <= m; k++) {
                    if (check(grid, i, j, k))
                        result = max(result, k);
                }
            }
        }
        return result;
    }
};
