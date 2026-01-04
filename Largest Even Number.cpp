//https://leetcode.com/contest/weekly-contest-483/problems/largest-even-number/description/


class Solution {
public:
    string largestEven(string s) {
        while(!s.empty()){
            if(s[s.size()-1]=='1') s.pop_back();
            else break;
        }
        return s;
    }
};
