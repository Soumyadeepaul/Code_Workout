//https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1


class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int rows=arr.size()+1;
        
        vector<vector<int>> dp(rows,vector<int> (target+1,0));
        for(int i=0;i<rows;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<rows;i++){
            for(int j=0;j<=target;j++){ // 0 can also be in arr
                if(arr[i-1]>j) dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
            }
        }
        return dp[rows-1][target];
    }
};
