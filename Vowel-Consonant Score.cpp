//https://leetcode.com/contest/weekly-contest-485/problems/vowel-consonant-score/description/


class Solution {
public:
    int vowelConsonantScore(string s) {
        int v=0,c=0;
        for(char i:s){
            if(i=='a'||i=='e'||i=='i'||i=='o'||i=='u') v++;
            else if(i>='a' && i<='z') c++;
        }
        if(c>0) return floor(v/c);
        return 0;
    }
};
