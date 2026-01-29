//https://leetcode.com/problems/clear-digits/description/

class Solution {
public:
    string clearDigits(string s) {
        string result="";
        for(char i:s){
            if(i>='0' && i<='9'){
                result.erase(result.end()-1);
                continue;
            }
            result+=i;
        }
        return result;
    }
};
