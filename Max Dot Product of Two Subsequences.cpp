//https://leetcode.com/problems/max-dot-product-of-two-subsequences/description/?envType=daily-question&envId=2026-01-08



class Solution {
public:
    int helper(vector<int>& nums1, vector<int>& nums2,int i,int j,vector<vector<int>> &dp){
        if(i==nums1.size()){
            if(j==0){
                return INT_MIN;
            }
            return 0;
        }
        if(j==nums2.size()){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int skip=helper(nums1,nums2,i+1,j,dp);
        int maxi=INT_MIN;
        for(int k=j;k<nums2.size();k++){
            maxi=max(maxi,nums1[i]*nums2[k]+helper(nums1,nums2,i+1,k+1,dp));
        }
        return dp[i][j]=max(maxi,skip);
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(),vector<int>(nums2.size(),-1));
        return helper(nums1,nums2,0,0,dp);   
    }
};
