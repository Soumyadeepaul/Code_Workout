//https://leetcode.com/problems/jump-game-v/description/?envType=daily-question&envId=2026-05-24


class Solution {
public:
    vector<int> dp;
    // greater to which it can jump   //using reverse rule
    int helper(vector<int> & arr, int &d, int idx){
        
        if(dp[idx]!=1) return dp[idx];
        int largestLeft=arr[idx], largestRight=arr[idx];
        for(int i=1;i<=d;i++){
            if(idx-i>-1){
                if(arr[idx-i]>largestLeft) {
                    largestLeft=arr[idx-i];
                    dp[idx]=max(dp[idx],1+helper(arr,d,idx-i));
                }
            }
            if(idx+i<arr.size()){
                if(arr[idx+i]>largestRight){
                    largestRight=arr[idx+i];
                    dp[idx]=max(dp[idx],1+helper(arr,d,idx+i));
                }
            }
        }
        return dp[idx];
    }
    int maxJumps(vector<int>& arr, int d) {
        dp.resize(arr.size(),1);
        int result=0;
        for(int i=0;i<arr.size();i++){
            result=max(result,helper(arr,d,i));
        }
        return result;
    }
};
