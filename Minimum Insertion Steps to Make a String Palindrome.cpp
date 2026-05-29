//https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/



class Solution {
public:
    int minInsertions(string s) {
        int l=s.size();
        vector<vector<int>> dp(l,vector<int>(l,0));

        for(int gap=0;gap<l;gap++){
            for(int i=0;i+gap<l;i++){
                int j=i+gap;
                if(i==j) dp[i][j]=1;
                else if(s[i]==s[j]) dp[i][j]=2+dp[i+1][j-1];
                else dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
            }
        }   
        return l-dp[0][l-1];
    }
};
