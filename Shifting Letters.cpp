//https://leetcode.com/problems/shifting-letters/description/


class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        vector<int> suff;
        long long val=0;
        for(int i=s.size()-1;i>-1;i--){
            val=(val+shifts[i])%26;
            suff.emplace_back(val);
        }
        for(int i=0;i<s.size();i++){
            long long store=s[i]-'a'+1;
            store+=suff[s.size()-i-1];
            if(store>26)
                store%=26;
            if(store==0)s[i]='z';
            else s[i]=store+'a'-1;
            
        }
        return s;
    }
};
