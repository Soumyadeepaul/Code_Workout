//https://leetcode.com/contest/biweekly-contest-175/problems/reverse-letters-then-special-characters-in-a-string/description/


class Solution {
public:
    string reverseByType(string s) {
        stack<char> letter;
        stack<char> special;

        for(char c: s){
            if(c>='a' && c<='z'){
                letter.push(c);
            }
            else{
                special.push(c);
            }
        }
        string result="";

        for(char c:s){
            if(c>='a' && c<='z'){
                char l=letter.top();
                letter.pop();
                result+=l;
            }
            else{
                char l=special.top();
                special.pop();
                result+=l;
            }
        }
        return result;
    }
};
