//https://leetcode.com/problems/four-divisors/description/?envType=daily-question&envId=2026-01-04


class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int result=0;
        vector<int> store;
        int count;
        for(int i:nums){
            count=0;
            store.clear();
            for(int j=1;j<=i;j++){
                if(i%j==0){
                    store.push_back(j);
                    count++;
                }
                if(count>4) break;
            }
            if(count==4) result+=accumulate(store.begin(),store.end(),0);
        }
        return result;
    }
};
