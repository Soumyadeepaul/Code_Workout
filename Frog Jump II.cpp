//https://leetcode.com/problems/frog-jump-ii/


// go alternative

class Solution {
public:
    int maxJump(vector<int>& stones) {
        int result=0;
        int lastIdx=0;
        int l=stones.size();
        for(int i=1;i<l;i++){
            if(i&1){
                if(i==1) result=max(result,abs(stones[0]-stones[i]));
                else{
                    result=max(result,abs(stones[i-2]-stones[i]));
                }
            }
            else{
                result=max(result,abs(stones[i-2]-stones[i]));
            }
        }
        return result;
    }
};
