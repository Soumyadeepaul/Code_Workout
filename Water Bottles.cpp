//https://leetcode.com/problems/water-bottles/description/?envType=daily-question&envId=2025-10-01


class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int count=0;
        int empty=0;
        while(true){
            count+=numBottles;
            empty+=numBottles;
            numBottles=0;
            if(empty>=numExchange){
                numBottles=empty/numExchange;
                empty%=numExchange;
            }
            else break;
            
        }
        count+=numBottles;
        return count;
    }
};
