//https://leetcode.com/problems/target-sum/solutions/7185860/c-intuition-is-s1-s2d-by-paulsoumyadeep7-wbke/

class Solution {
public:
// intuition -> convert 2 subsets... s1 - s2
    void subset(vector<int> &nums,int &target,int i, int &l,int &summ,int &result,int &stack){
        if(stack-summ==target)
        {            
            result++;

        }
        for(;i<l;i++){
            stack+=nums[i];
            summ-=nums[i];
            subset(nums,target,i+1,l,summ,result,stack);
            stack-=nums[i];
            summ+=nums[i];
        }
        return;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int l=nums.size();
        int summ=accumulate(nums.begin(),nums.end(),0);
        int result=0;
        int stack=0;
        subset(nums,target,0,l,summ,result,stack);
        return result;
    }
};





/////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    // int result=0;
    // void helper(vector<int>& nums, int target, int idx, int summ){
    //     if(idx==nums.size()){
    //         if(summ==target) result++;
    //         return;
    //     }
    //     helper(nums,target, idx+1,summ+nums[idx]);
    //     helper(nums,target, idx+1,summ-nums[idx]);
    // }
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     helper(nums,target,0,0);
    //     return result;
    // }

    int result=0;
    int findTargetSumWays(vector<int>& nums, int target) {
        int l=nums.size();
        vector<unordered_map<int,int>> dp(l);
        dp[l-1][-nums[l-1]]+=1;  // +0 and -0 should count 2
        dp[l-1][nums[l-1]]+=1;
        for(int i=nums.size()-2;i>-1;i--){
            unordered_map<int,int> &temp=dp[i+1];

            for(auto p:temp){
                dp[i][p.first+nums[i]]+=p.second;
                dp[i][p.first-nums[i]]+=p.second;
            }
        }

        return dp[0][target];
    }
};
