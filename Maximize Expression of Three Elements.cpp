//https://leetcode.com/contest/weekly-contest-476/problems/maximize-expression-of-three-elements/
class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=nums.size();
        return nums[l-1]+nums[l-2]-nums[0];
    }
}
