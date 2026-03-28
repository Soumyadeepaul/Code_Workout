//https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/


class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count=0,x,y;
        while(!(start==0 && goal==0)){ //unless both r 0
            x=start&1;
            y=goal&1;
            start>>=1;
            goal>>=1;
            if(x!=y)count++; 
        }
        return count;
    }
};
