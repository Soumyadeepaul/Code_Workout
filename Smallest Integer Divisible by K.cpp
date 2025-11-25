//https://leetcode.com/problems/smallest-integer-divisible-by-k/description/?envType=daily-question&envId=2025-11-25

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0 || k%5==0) return -1;
        int count=1;
        unsigned long long n=1;
        while (true){
            if(n%k==0) return count;
            n=n*10+1;
            count++;
            n=n%k;
        }
    }
};
