//https://leetcode.com/problems/rotate-string/description/?envType=daily-question&envId=2026-05-03


class Solution {
public:
    bool rotateString(string s, string goal) {
        int length=s.size();
        while(length--!=0){
            char first=s[0];
            s=s.substr(1)+first;
            if(s==goal) return true;
        }
        return false;
    }
};
