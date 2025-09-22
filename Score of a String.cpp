//https://leetcode.com/problems/score-of-a-string/description/


class Solution {
public:
    int scoreOfString(string s) {
        int result=0;
        int l=s.size()-1;
        for(int i=0;i<l;i++){
            result+=abs(s[i]-s[i+1]);
        }
        return result;
    }
};
