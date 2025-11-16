//https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

class Solution {
public:
    int matrixMultiplication(vector<int> &arr) {
        int l = arr.size();
        vector<vector<int>> dp(l, vector<int>(l, 0));

        int i = 0, j = 0;
        int col = 1;

        while (j < l) {
            while (i < l && j < l) {
                if (j - i >= 2) { // at least 2 matrices
                    dp[i][j] = INT_MAX;
                    for (int k = i + 1; k < j; k++) {
                        int cost = dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j];
                        dp[i][j] = min(dp[i][j], cost);
                    }
                }
                i++;
                j++;
            }
            j = col;
            col++;
            i = 0;
        }

        return dp[0][l - 1];
    }
};


///////////////////////////////////////////////////////////////////////////



class Solution {
public:
    int matrixMultiplication(vector<int> &arr) {
        int l = arr.size()-1;
        vector<vector<int>> dp(l, vector<int>(l, 0));
        for(int gap=0;gap<l;gap++){
            for(int i=0;i+gap<l;i++){
                int j=i+gap;
                if(i==j) dp[i][j]=0;
                else{
                    dp[i][j]=INT_MAX;
                    for(int k=i;k<j;k++){
                        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+(arr[i]*arr[k+1]*arr[j+1]));
                    }
                }
            }
        }
        return dp[0][l - 1];
    }
};

