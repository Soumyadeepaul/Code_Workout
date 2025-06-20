#https://leetcode.com/problems/power-of-two/description/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n==1){
            return 1;
        }
        if (n%2==0){
            long int val=1;
            while (1){
                if (n<val){
                    return 0;
                }
                else if(n==val){
                    return 1;

                }
                else{
                    val=val<<1;
                }
            }
        }
        return 0;
    }
};
