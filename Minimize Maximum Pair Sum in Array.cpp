//https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/?envType=daily-question&envId=2026-01-24


class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        int result=0;
        while(i<nums.size()/2 && j>=nums.size()/2){
            result=max(result,nums[i]+nums[j]);
            i++;
            j--;
        }
        return result;
    }
};
