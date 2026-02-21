//https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/?envType=daily-question&envId=2026-02-21


class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        vector<int> setBit(right+1,0);
        setBit[1]=1;
        int result=0;
        vector<int> p={2, 3, 5, 7, 11, 13, 17 , 19};
        unordered_set<int> prime(p.begin(),p.end());
        for(int i=2;i<right+1;i++){
            int count=setBit[i>>1];
            if(i&1) count++;
            setBit[i]=count;
            if(i>=left && prime.count(count)) result++;
        }
        return result;
    }
};
