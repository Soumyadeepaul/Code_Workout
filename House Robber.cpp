//https://leetcode.com/problems/house-robber/description/


class Solution {
public:
    int rob(vector<int>& nums) {
        int l=nums.size();
        if(l<=2) return *max_element(nums.begin(),nums.end());
        vector<int> dp(l,0);
        int maxi=INT_MIN;
        dp[0]=nums[0];
        dp[1]=nums[1];
        for(int i=2;i<l;i++){
            dp[i]+=max(nums[i]+*max_element(dp.begin(),dp.begin()+i-1),dp[i-1]);
            maxi=max(maxi,dp[i]);
        }
        return maxi;

    }
};
