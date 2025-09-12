//https://leetcode.com/problems/vowels-game-in-a-string/description/?envType=daily-question&envId=2025-09-12


class Solution {
public:
    bool doesAliceWin(string s) {
        unordered_set<char> vowel;
        vowel.insert('a');
        vowel.insert('e');
        vowel.insert('i');
        vowel.insert('o');
        vowel.insert('u');
        int l=s.size();
        for(int i=0;i<l;i++){
            if(find(vowel.begin(),vowel.end(),s[i])!=vowel.end()){
                return true;
            }
        }
        return false;
    }
};
