//https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/description/?envType=daily-question&envId=2026-05-10


class Solution {
public:
    vector<int> dp;
    int helper(vector<int>& nums, int idx, int &target){
        if(idx==0) return dp[idx]=0;
        
        if(dp[idx]!=-2) return dp[idx]; //-2 means not yet explored
        
        for(int i=idx-1;i>-1;i--){
            int val=nums[i]-nums[idx];
            if(-target<=val && val<=target) dp[idx]=max(dp[idx],1+helper(nums,i,target));
        }
        if(dp[idx]==0) dp[idx]=-1; //cant be reached
        return dp[idx];
    }
    int maximumJumps(vector<int>& nums, int target) {
        int length=nums.size();
        dp.resize(length,-2);
        int result=helper(nums,length-1,target);
        return (result==-2) ? -1:result;
    }
};
