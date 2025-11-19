//https://leetcode.com/problems/keep-multiplying-found-values-by-two/?envType=daily-question&envId=2025-11-19

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==original) original*=2;
        }
        return original;
    }
};
