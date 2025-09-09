//https://leetcode.com/problems/divide-two-integers/description/


class Solution {
public:
    int divide(int n, int d) {
        if(d==1) return n;
        long long count=0;
        int sign=0;
        long dividend=(long)n,divisor=(long)d;
        if(n<0 && d<0){
            sign=0;
        }
        else if(n<0 || d<0){
            sign=1;
        }
        dividend=abs((long)n);
        divisor=abs((long)d);
        

        while (dividend>=divisor){
            for(int i=0;i<32;i++){
                if (dividend<=(divisor<<i)){
                    if(i==0){
                        count+=1;
                        dividend=dividend-divisor;
                    }
                    else{
                        count+=1<<(i-1);
                        if(count>INT_MAX) return INT_MAX;
                        else if(count<INT_MIN) return INT_MIN; 
                        dividend=dividend-(divisor<<(i-1));
                    }
                    break;
                }
            }
        }
        if(count>INT_MAX) return INT_MAX;
        else if(count<INT_MIN) return INT_MIN;
        if(sign==1) return -count;
        return count;
    }
};
