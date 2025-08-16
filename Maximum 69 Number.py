#https://leetcode.com/problems/maximum-69-number/description/?envType=daily-question&envId=2025-08-16

class Solution {
public:
    int maximum69Number (int num) {
        long int position=-1;
        long int rem;
        long int store=0;
        int num1=num;
        int encounter=0;
        while(num1>0){
            rem=num1%10;
            num1=num1/10;
            position++;
            if(rem==6){
                encounter=1;
                store=position;
            }
        }
        if (encounter==1){
            num=num+(3*pow(10,store));
        }
        return num;


    }
};
