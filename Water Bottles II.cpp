//https://leetcode.com/problems/water-bottles-ii/description/?envType=daily-question&envId=2025-10-02


class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int result=0;
        int fullB=numBottles;
        int emptyB=0;
        int numE=numExchange;

        while(fullB!=0){
            result+=fullB;
            emptyB+=fullB;
            fullB=0;
            while(emptyB>=numE){
                fullB+=1;
                emptyB-=numE;
                numE++;
            }
        }
        return result;
    }
};
