//https://www.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

class Solution {
  public:
    int lcs(string &s1, string &s2) {
        // code here
        vector<vector<int>> dp(2,vector<int>(s1.size()+1,0));
        int idx=1;
        while(idx<=s2.size()+1){
            for(int j=1;j<s1.size()+1;j++){
                if(s2[idx-1]==s1[j-1])
                    dp[1][j]=dp[0][j-1]+1;
                else
                    dp[1][j]=max(dp[0][j],dp[1][j-1]);
            }
            idx++;
            dp[0]=dp[1];
        }
        return dp[1][s1.size()];
        
    }
};
