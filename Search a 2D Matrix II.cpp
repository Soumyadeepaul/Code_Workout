//https://leetcode.com/problems/search-a-2d-matrix-ii/description/?envType=problem-list-v2&envId=divide-and-conquer


class Solution {
public:
    pair<bool,int> binarySearchRow(const vector<int>& row, int target, int l, int r) {
        int lastMid = r;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (row[mid] == target)
                return {true, mid};
            else if (row[mid] < target)
                l = mid + 1;
            else {
                lastMid = mid; 
                r = mid - 1;
            }
        }
        return {false, lastMid};
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int last = matrix[0].size() - 1;
        for (int i = 0; i < matrix.size(); ++i) {
            auto [found, newLast] = binarySearchRow(matrix[i], target, 0, last);
            last = newLast; 
            if (found) return true;
        }
        return false;
    }
};
