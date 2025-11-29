//https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/description/?envType=daily-question&envId=2025-11-29

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int summ=accumulate(nums.begin(),nums.end(),0);
        return summ%k;
    }
};
