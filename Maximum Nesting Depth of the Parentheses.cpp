//https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/


class Solution {
public:
    int maxDepth(string s) {
        int result=0;
        int open=0;
        for(char c:s){
            if(c=='(') open++;
            else if(c==')'){
                result=max(result,open);
                open--;
            }
        }
        return result;
    }
};
