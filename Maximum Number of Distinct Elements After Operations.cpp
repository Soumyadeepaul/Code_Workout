//https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/description/?envType=daily-question&envId=2025-10-18


class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        unordered_set<int> present;
        int count=1;
        int prev=nums[0];
        int step=-k;
        vector<int> dp(nums.size());
        dp[0]=nums[0]+step;
        int diff;
        for(int i=1;i<nums.size();i++){
            diff=dp[i-1]-nums[i];
            diff++;
            if(diff<-k){
                diff=-k;
                dp[i]=nums[i]+diff;
                continue;
            }
            else if(diff>k){
                diff=k;
                dp[i]=nums[i]+diff;
                continue;
            }
            dp[i]=nums[i]+diff;
        }
        for(int i=1;i<dp.size();i++){
            if(dp[i]!=dp[i-1]) count++;
        }
        return count;
    }
};
