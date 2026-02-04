//https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/


class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {

        unordered_map<int,int> store;
        for(int i=0;i<arr.size();i++){
            store[arr[i]]=i;
        }
        int l = arr.size();
        unordered_map<int,unordered_map<int,int>> dp;
        int maxi=0;
        for(int i = l-1; i >-1; i--){
            for(int j = l-1; j >i; j--){
                int nextt=arr[i]+arr[j];
                int length=2;
                if(store.find(nextt)!=store.end()){
                    length=1+dp[j][store[nextt]];
                    maxi=max(length,maxi);
                }
                dp[i][j]=length;
            }
        }
        return maxi;
    }
};
