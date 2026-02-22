//https://leetcode.com/contest/weekly-contest-490/problems/find-the-score-difference-in-a-game/description/


class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int a=0;
        int b=0;
        bool activeA=1;
        int tracker=-1;
        for(int i:nums){
            if(++tracker %6 ==5) activeA=!activeA;
            if(i&1){
                if(activeA==1){
                    b+=i;
                    activeA=0;
                }
                else{
                    activeA=1;
                    a+=i;
                }
            }
            else{
                if(activeA==1) a+=i;
                else b+=i;
            }
        }
        
        return a-b;
    }
};
