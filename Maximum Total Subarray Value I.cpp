//https://leetcode.com/contest/weekly-contest-468/problems/maximum-total-subarray-value-i/description/


class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxi=*max_element(nums.begin(),nums.end());
        int minn=*min_element(nums.begin(),nums.end());
        int diff=maxi-minn;
        return (long long)diff*k;
    }
};©leetcode
