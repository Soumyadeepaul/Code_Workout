//https://leetcode.com/problems/maximum-length-of-pair-chain/description/?envType=problem-list-v2&envId=dynamic-programming


class Solution {
private:
    
public:
    int helper(vector<vector<int>>& pairs,int idx,int previous, int &result, vector<int> &dp){
        if(idx==pairs.size()) return 0;
        if(dp[previous+1000]!=0) return dp[previous+1000];
        int maxi=0;
        for(int i=idx;i<pairs.size();i++){
            if(previous<pairs[i][0]){
                maxi=max(maxi,1+helper(pairs,i+1,pairs[i][1],result,dp));
            }
            dp[previous+1000]=maxi;
            result=max(result,maxi);
        }
        return dp[previous+1000];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.size()==1) return 1;
        int result=0,previous=-1000,idx=0;
        sort(pairs.begin(),pairs.end());
        vector<int> dp(2001,0);
        int s=helper(pairs,idx,previous,result,dp);
        for(int i:dp) cout<<i<<" "<<endl;
        return result;
    }
};
