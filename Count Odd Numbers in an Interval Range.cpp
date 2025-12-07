//https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/description/?envType=daily-question&envId=2025-12-07

class Solution {
public:
    int countOdds(int low, int high) {
        if(low%2==0 && high%2==0) return (high-low)/2;
        else return (high-low)/2 +1;
    }
};
