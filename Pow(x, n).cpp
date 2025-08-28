//https://leetcode.com/problems/powx-n/description/

class Solution {
public:
    double myPow(double x, int m) {
        double one=1.0;
        if(x==one || m==1){
            return x;
        }
        bool powerChanged=false;
        long int n=(long int) m;
        if(n<0){
            n=-n;
            powerChanged=true;
        }

        double result=1.0;
        int rem;
        while (n){
            rem=n%2;
            n=n/2;
            if(rem==1){
                result=result*x;
            }
            x=x*x;
        }

        if (powerChanged==true){
            return 1/result;
        }
        return result;
    }
};
