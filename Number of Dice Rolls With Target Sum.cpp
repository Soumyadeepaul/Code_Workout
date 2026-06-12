//https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/

class Solution {
public:
    int mod=1e9+7;
    int count=0;
    vector<vector<long long>> dp;
    long long helper(int idx,int n, int k, int target, int summ){
        if(summ>target) return 0;
        int find=target-summ; //is it possible to make find.. then we will get target
        if(idx==n){
            return dp[idx][find] = (find >= 1 && find <= k); // at last dice.. if find is range of 1 to k
        }
        if(dp[idx][find]!=-1) return dp[idx][find]; //if calculated before
        if(dp[idx][find]==-1) dp[idx][find]=0; //is getting searched
        for(int i=1;i<=k;i++){
            dp[idx][find]=(dp[idx][find]+helper(idx+1,n,k,target,summ+i))%mod;
        }
        return dp[idx][find];
    }
    int numRollsToTarget(int n, int k, int target) {
        dp.assign(n+1,vector<long long>(target+1,-1));
        return (int)helper(1,n,k,target,0);
    }
};
