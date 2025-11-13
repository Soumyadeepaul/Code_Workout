//https://leetcode.com/problems/concatenation-of-array/description/?envType=problem-list-v2&envId=dsa-linear-shoal-array-i

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> num1(nums.begin(),nums.end());
        for(int i:nums) num1.push_back(i);
        return num1;
    }
};
