//https://leetcode.com/problems/sum-of-subarray-ranges/description/

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        vector<vector<pair<int,int>>> dp(nums.size(),vector<pair<int,int>>(nums.size(),{0,0}));
        long long result=0;
        int j=0,last=nums.size();
        for(int gap=0;gap<nums.size();gap++){
            int i=0;
            while(i<last){
                j=i+gap;
                if(i==j) dp[i][j]={nums[i],nums[i]};
                else{
                    dp[i][j]={max({dp[i+1][j].first,dp[i][j-1].first,nums[i]}),min({dp[i+1][j].second,dp[i][j-1].second,nums[i]})};
                    result+=dp[i][j].first-dp[i][j].second;
                }
                i++;
            }
            last--;
        }
        return result;
    }
};
