//https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/?envType=daily-question&envId=2026-01-25


class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k==1 || nums.size()==1) return 0;
        sort(nums.begin(),nums.end());
        int result=INT_MAX;
        for(int i=k;i<nums.size()+1;i++){
            result=min(result,nums[i-1]-nums[i-k]);
        }
        return result;
    }
};
