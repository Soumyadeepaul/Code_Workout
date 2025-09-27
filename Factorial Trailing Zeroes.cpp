//https://leetcode.com/problems/factorial-trailing-zeroes/description/?envType=study-plan-v2&envId=top-interview-150


class Solution {
public:
    int trailingZeroes(int n) {
        int result=0;
        int deno=5;
        int power=5;
        while (n>=deno){
            result+=floor(n/deno);
            deno=deno*power;
        }
        return result;
    }
};
