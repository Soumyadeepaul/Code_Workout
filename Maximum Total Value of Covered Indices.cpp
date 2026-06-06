//https://leetcode.com/problems/maximum-total-value-of-covered-indices/description/

class Solution {
public:
    typedef long long ll;
    vector<vector<ll>> dp;
    ll helper(vector<int> &nums, int idx, string &s, bool shift){
        if(idx==nums.size()){
            return 0;
        }
        if(dp[idx][shift]!=-1) return dp[idx][shift];
        if(s[idx]=='1'){
            if(idx==0) dp[idx][shift]=nums[idx]+helper(nums,idx+1,s,0);
            else{
                //previous shifted
                if(shift==1) {
                    dp[idx][shift]=nums[idx-1]+helper(nums,idx+1,s,1); //shifted
                    dp[idx][shift]=max(dp[idx][shift],nums[idx]+helper(nums,idx+1,s,0)); //shifted
                }
                else dp[idx][shift]=nums[idx]+helper(nums,idx+1,s,0); //not shifted
                
            }
        }
        else dp[idx][shift]=helper(nums,idx+1,s,1); //if 0 then shiftable
        return dp[idx][shift];
    }
    long long maxTotal(vector<int>& nums, string s) {
        int l=s.size();
        dp.assign(l,vector<ll>(2,-1));
        return helper(nums,0,s,0);

    }
};
