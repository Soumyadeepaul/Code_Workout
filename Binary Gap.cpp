//https://leetcode.com/problems/binary-gap/description/?envType=daily-question&envId=2026-02-22

class Solution {
public:
    int binaryGap(int n) {
        int result=0;
        int count=0;
        vector<int> store;
        while(n){
            store.push_back(n&1);
            n=n>>1;
        }
        for(int i=store.size()-1;i>-1;i--){
            if(store[i]==1 && count!=0){
                result=max(result,count);
                count=0;
            }
            count++;
        }

        return result;
    }
};
