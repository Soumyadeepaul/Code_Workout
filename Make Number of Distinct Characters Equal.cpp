//https://leetcode.com/problems/make-number-of-distinct-characters-equal/description/

class Solution {
public:
    bool isItPossible(string word1, string word2) {
        unordered_map<char, int> mp1, mp2;
        //add all chars to the map
        for(char ch: word1) mp1[ch]++;
        for(char ch: word2) mp2[ch]++;

        for(int i=0; i < 26; i++){
            for(int j=0; j < 26; j++){
                char ch1 = i + 'a', ch2 = j + 'a';
                if(mp1.count(ch1) && mp2.count(ch2)){
                    //remove one char from both to swap
                    if(--mp1[ch1] == 0) mp1.erase(ch1);
                    if(--mp2[ch2] == 0) mp2.erase(ch2);

                    //add the new char
                    mp1[ch2]++;
                    mp2[ch1]++;

                    //if distinct chars in both, return true
                    if(mp1.size() == mp2.size())
                        return true;

                    //add back the removed chars, also remove the new added chars
                    if(--mp1[ch2] == 0) mp1.erase(ch2);
                    if(--mp2[ch1] == 0) mp2.erase(ch1);
                    mp1[ch1]++;
                    mp2[ch2]++;
                }
            }
        }
        return false;
    }
};
