//https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/?envType=daily-question&envId=2026-03-05


class Solution {
public:
    int helper(string s, char flag){
        int c1=0;
        char state=flag;
        for(char i:s){
            if(i!=flag) c1++;
            flag=(flag=='0')?'1':'0';
        }
        if(state =='1') return c1;
        return min(c1,helper(s,'1'));
    }
    int minOperations(string s) {
        int result=1e9;
        return helper(s,'0');
    }
};
