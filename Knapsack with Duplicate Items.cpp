//https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

//TLE 1110/1120

class Solution {
  public:
    int helper(int idx,vector<int>& val, vector<int>& wt, int capacity, int curr,unordered_map<int,unordered_map<int,int>>&dp, int profit, int &l){
        if(idx==l || capacity-curr<=0){
            return 0;
        }
        if(dp.count(idx) && dp[idx].count(capacity-curr)) return dp[idx][capacity-curr];
        int notTake=helper(idx+1,val,wt,capacity,curr,dp,profit,l);
        int take=0;
        if(curr+wt[idx]<=capacity){
            take=val[idx]+helper(idx,val,wt,capacity,curr+wt[idx],dp,profit+val[idx],l);
        }
        return dp[idx][capacity-curr]=max(take,notTake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        unordered_map<int,unordered_map<int,int>>dp;
        int l=val.size();
        int result=helper(0,val,wt,capacity,0,dp,0,l);
        return result;
    }
};
