//https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/description/?envType=daily-question&envId=2026-03-06


class Solution {
public:
    bool checkOnesSegment(string s) {
        int zero=0;
        for(int i=1;i<s.size();i++){
            if(s[i]=='0') zero=1;
            else if(zero==1) return false; 
        }
        return true;
    }
};
