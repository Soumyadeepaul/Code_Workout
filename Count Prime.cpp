//https://leetcode.com/problems/count-primes/description/

class Solution {
public:
    // bool prime(int i){
    //     for(int j=2;j<=sqrt(i);j++){
    //         if(i%2==0) return false;
    //     }
    //     return true;
    // }
    int countPrimes(int n) {
        // make array of 2 to n-1 elements all with 1
        // 2 as it is prime... mark all multiples of 2 by 0
        // similarly for 3
        // at 4 as it is already 0.. dont do anything
        // for primes just go and set it multiples to 0
        // if the index is not marked as 0 by any of the previous multiples... its prime automatically

        if(n<=1) return 0;
        vector<int> dp(n,1);
        int count=0;
        int j;
        for(int i=2;i<n;i++){
            if(dp[i]==0)continue;
            //check prime
            if (dp[i]==1){ // if true
                count++;
                for(j=2*i;j<n;j+=i){
                    dp[j]=0;
                }
            }
        }
        return count;
    }
};
