//https://leetcode.com/problems/smallest-number-with-all-set-bits/?envType=daily-question&envId=2025-10-29


class Solution {
public:
    int smallestNumber(int n) {
        int count=0;
        while(n){
            n=n/2;
            count++;
        }
        return pow(2,count)-1;
        
    }
};
