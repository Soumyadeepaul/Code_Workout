//https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/description/?envType=daily-question&envId=2025-10-23


class Solution {
public:
    bool hasSameDigits(string s) {
        string newS="";
        while(s.size()>2){
            int a,b;
            for(int i=0;i<s.size()-1;i++){
                a=s[i]-'0';
                b=s[i+1]-'0';
                newS+=to_string((a+b)%10);
            }
            s=newS;
            newS="";
        }
        return s[0]==s[1];
    }
};
