//https://leetcode.com/problems/count-asterisks/description/
class Solution {
public:
    int countAsterisks(string s) {
        bool consider=true;
        int l=s.size()-1;
        int i=0;
        int count=0;
        while (i<=l){
            if (s[i]=='|'){
                consider=!consider;
            }
            else if(consider==true){
                if(s[i]=='*'){
                    count++;
                }
            }
            i++;
        }
        return count;
    }
};
