//https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/description/?envType=daily-question&envId=2026-03-01

class Solution {
public:
    int minPartitions(string n) {
        int maxi=0;
        for(char i:n){
            if(maxi<i-'0') maxi=i-'0';
        }
        return maxi;
    }
};
