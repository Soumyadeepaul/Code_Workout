//https://leetcode.com/problems/lemonade-change/description/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;
        int l=bills.size();
        for(int i=0;i<l;i++){
            if(bills[i]==5) five+=1;
            else if(bills[i]==10){
                if(five==0) return false;
                else{
                    five-=1;
                    ten+=1;
                }
            }
            else{
                if(five>0 && ten>0){
                    five-=1;
                    ten-=1;
                }
                else if(five>2) five-=3;
                else return false;
            }
                
        }
        return true;
    }
};
