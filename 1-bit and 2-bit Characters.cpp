//https://leetcode.com/problems/1-bit-and-2-bit-characters/?envType=daily-question&envId=2025-11-18

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i=0;
        int l=bits.size();
        while(i<l){
            if(i==l-1) return true;
            else{
                if(bits[i]==0) i++;
                else i+=2;
            }
        }
        return false;
    }
};
