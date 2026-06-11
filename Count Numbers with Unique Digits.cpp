//https://leetcode.com/problems/count-numbers-with-unique-digits/description/?envType=problem-list-v2&envId=backtracking


class Solution {
public:
    int count=0;
    void helper(int idx, int n, string num){
        if(idx==n+1) return;
        count++;
        for(int i=0;i<=9;i++){
            if(idx!=0){
                if(idx-1==0 && num[idx-1]=='0') return;
                bool common=false;
                for(char j:num){
                    if(j==(i+'0')) {
                        common=true;
                        break;
                    }
                }
                if(common==false) helper(idx+1,n,num+to_string(i));
            }
            else helper(idx+1,n,num+to_string(i));
        }
    }
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        helper(0,n,"");
        return count-1; //-1 for blank was counted
    }
};
