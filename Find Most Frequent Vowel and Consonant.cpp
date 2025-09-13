//https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/description/?envType=daily-question&envId=2025-09-13

class Solution {
public:
    int maxFreqSum(string s) {
        unordered_set<char> vowel;
        vowel.insert('a');
        vowel.insert('e');
        vowel.insert('i');
        vowel.insert('o');
        vowel.insert('u');
        int l=s.size();
        unordered_map<char,int> freq;
        for(int i=0;i<l;i++){
           freq[s[i]]++;
           
        }
        int v=0;
        int c=0;
        for(auto &pair:freq){
            if(find(vowel.begin(),vowel.end(),pair.first)==vowel.end()){
                c=max(c,pair.second);
            }
            else{
                v=max(v,pair.second);
            }
        }
        return c+v;
    }
};
