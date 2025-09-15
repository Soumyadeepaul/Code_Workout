//https://leetcode.com/problems/number-of-longest-increasing-subsequence/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int l=nums.size();
        vector<int> dp(l,1);
        vector<int> count(l,1);
        int c=0;
        int maxx=INT_MIN;
        for(int i=1;i<l;i++){
            for(int j=i-1;j>-1;j--){
                if(nums[i]>nums[j]){
                    if(dp[i]<dp[j]+1){ //if new length formed
                        dp[i]=dp[j]+1;
                        count[i]=count[j]; //
                    }
                    else if(dp[i]==dp[j]+1) count[i]+=count[j]; //if same length increase by count[j]
                    
                }
            }
            maxx=max(maxx,dp[i]); //get the max length
        }
        for(int i=0;i<l;i++){ 
            if(dp[i]==maxx){ c=c+count[i];}}// loop and count max length... c+=count[i]
        if(l==1) return 1;
        return c;
    }
};
