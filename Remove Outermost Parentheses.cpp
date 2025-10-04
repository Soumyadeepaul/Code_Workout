//https://leetcode.com/problems/remove-outermost-parentheses/


class Solution {
public:
    string removeOuterParentheses(string s) {
        int open=0;
        string result;
        int l=s.size();
        for(int i=0;i<l;i++){
            if(s[i]=='(' && open==0) open++;
            else if(s[i]=='(' && open >0) {
                result+='(';
                open++;
            }
            else if(s[i]==')' && open >1){
                result+=')';
                open--;
            }
            else{
                open--;
            }
        }
        return result;
    }
};
