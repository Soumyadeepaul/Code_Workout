//https://leetcode.com/problems/jump-game-iii/description/


class Solution {
public:
    int helper(vector<int>& arr, int pos,vector<int> &dp){
        if(arr[pos]==0) return true;
        if(dp[pos]!=0) return dp[pos];
        dp[pos]=2;
        if(pos-arr[pos]>-1 && helper(arr,pos-arr[pos],dp)==1) return dp[pos]=1;
        if(pos+arr[pos]<arr.size() && helper(arr,pos+arr[pos],dp)==1) return dp[pos]=1; 
        return dp[pos];
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int> dp(arr.size(),0);
        return (helper(arr,start,dp)==1) ? true: false;
    }
};
