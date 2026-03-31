//https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/


class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0,j=0;
        while(j<s.size()){
            if(t[i]==s[j]) i++;
            j++;
        }
        return t.size()-i;
    }
};
