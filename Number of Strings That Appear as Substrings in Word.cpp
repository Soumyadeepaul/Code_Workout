//https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/description/?envType=daily-question&envId=2026-06-29


class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_map<string,int> freq;
        for(auto p:patterns) freq[p]++;
        int count=0;
        for(int i=0;i<word.size();i++){
            string temp="";
            for(int j=i;j<word.size();j++){
                temp+=word[j];
                count+=freq[temp];
                freq.erase(temp);
            }
        }
        return count;
    }
};
