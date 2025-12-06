//https://leetcode.com/problems/count-partitions-with-max-min-difference-at-most-k/description/?envType=daily-question&envId=2025-12-06
//TLE

class Solution {
private:
    int mod=pow(10,9)+7;
public:
    int helper(vector<int>& nums, int &k,vector<int>& dp,int idx,int &l){

        if(idx==l) return 1;
        if(dp[idx]!=-1) return dp[idx];
        long long ways=0;
        int minn=nums[idx],maxx=nums[idx];
        for(int i=idx;i<l;i++){
            minn=min(minn,nums[i]);
            maxx= (maxx>nums[i]) ? maxx : nums[i];
            if(maxx-minn> k) break;
            ways=(ways+helper(nums,k,dp,i+1,l))%mod;
        }
        return dp[idx]=ways;
    }
    int countPartitions(vector<int>& nums, int k) {
        int l=nums.size();
        vector<int> dp(l,-1);
        return helper(nums,k,dp,0,l);
    }
};
