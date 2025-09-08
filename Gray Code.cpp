//https://leetcode.com/problems/gray-code/description/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        for(int i=0;i<pow(2,n);i++){
            result.push_back(i^i>>1);
        }
        return result;
    }
};
