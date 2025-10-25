//https://leetcode.com/problems/calculate-money-in-leetcode-bank/description/?envType=daily-question&envId=2025-10-25


class Solution {
public:
    int totalMoney(int n) {
        int completeWeeks=n/7;
        int rem=n%7;
        int result=0;
        int ending=7;
        for(int i=0;i<completeWeeks;i++){
            result+=(ending*(ending+1))/2;
            result-=(i*(i+1))/2;
            ending+=1;
        }
        while(rem){
            result+=completeWeeks+1;
            completeWeeks++;
            rem--;
        }
        return result;

    }
};
