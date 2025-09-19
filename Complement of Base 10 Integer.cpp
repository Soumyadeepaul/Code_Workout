//https://leetcode.com/problems/complement-of-base-10-integer/description/


class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        int val=0;
        int power=1;
        int x=n;
        while(x){
            x=x/2;
            val+=power;
            power=power<<1;
        }
        return n^val;
    }
};
