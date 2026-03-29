//https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/?envType=daily-question&envId=2026-03-29


class Solution {
public:
    bool helper(string &s1, string s2, int idx){
        if(s1==s2){
            return true;
        }
        for(int i=idx;i<2;i++){
            swap(s2[i],s2[i+2]);
            if(helper(s1,s2,i+1)) return true;
            swap(s2[i],s2[i+2]);
        }
        return false;
    }
    bool canBeEqual(string s1, string s2) {
        return helper(s1,s2,0);
    }
};
