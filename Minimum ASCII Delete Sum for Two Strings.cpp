//https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/?envType=daily-question&envId=2026-01-10


class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        //longest common subsequences
        int l1=s1.size(),l2=s2.size();
        vector<vector<int>> dp(l1+1,vector<int>(l2+1,0));
        for(int i=1;i<l1+1;i++){
            for(int j=1;j<l2+1;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+s1[i-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int summ1=0,summ2=0;
        for(int i=0;i<l1;i++){
            summ1+=s1[i];
        }
        for(int i=0;i<l2;i++){
            summ2+=s2[i];
        }
        return summ1+summ2-(2*dp[l1][l2]);

    }
};
