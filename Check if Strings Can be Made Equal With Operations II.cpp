//https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/?envType=daily-question&envId=2026-03-30


class Solution {
public:
    
    bool checkStrings(string s1, string s2) {
        unordered_map<char,int> even;
        unordered_map<char,int> odd;
        for(int i=0;i<s1.size();i++){
            if(i&1) odd[s1[i]]++;
            else even[s1[i]]++;
        }
        for(int i=0;i<s2.size();i++){
            if(i&1){
                odd[s2[i]]--;
                if(odd[s2[i]]<0) return false;
            }
            else{
                even[s2[i]]--;
                if(even[s2[i]]<0) return false;
            }
        }
        return true;

    }
};
