//https://leetcode.com/problems/prime-pairs-with-target-sum/description/


class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<int> prime(n+1,1);
        for(int i=2;i<n+1;i++){
            if(prime[i]==1){
                for(int j=i+i;j<n+1;j=j+i){
                    prime[j]=0;
                }
            }
        }
        vector<vector<int>> result;
        for(int i=2;i<n+1;i++){
            if(prime[i]==1){
                int left=n-i;
                if(left>=i){
                    if(prime[left]==1){
                        result.push_back({i,left});
                    }
                }
            }
        }
        return result;
    }
};
