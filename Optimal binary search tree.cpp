//https://www.geeksforgeeks.org/problems/optimal-binary-search-tree2214/1



// User function Template for C++

class Solution {
  public:
    int optimalSearchTree(int keys[], int freq[], int n) {
        // code here
        int l = n;
        vector<vector<int>> dp(l, vector<int>(l, 0));
        vector<vector<int>> w(l, vector<int>(l, 0));
        for(int gap=0;gap<l;gap++){
            for(int i=0;i+gap<l;i++){
                int j=i+gap;
                if(i==j){
                    w[i][i] = freq[i];
                    dp[i][i] = freq[i];
                    continue;
                }
                dp[i][j]=INT_MAX;
                w[i][j]=w[i][j-1]+freq[j];
                for(int k=i;k<=j;k++){
                    int left  = (k > i) ? dp[i][k-1] : 0;
                    int right = (k < j) ? dp[k+1][j] : 0;
                    dp[i][j]=min(dp[i][j],left+right+w[i][j]);
                }
            }
        }
        return dp[0][l - 1];
    }
};
