//https://leetcode.com/problems/sort-vowels-in-a-string/?envType=daily-question&envId=2025-09-11

class Solution {
public:
    string sortVowels(string s) {
        vector<char>vowel={'a','e','i','o','u','A','E','I','O','U'};
        vector<int> index;
        vector<char> store;
        for(int i=0;i<s.size();i++){
            if(find(vowel.begin(),vowel.end(),s[i])!=vowel.end()){
                index.push_back(i);
                store.push_back(s[i]);
            }
        }
        sort(store.begin(),store.end());
        int j=0;
        for(int i=0;i<index.size();i++){
            s[index[i]]=store[j];
            j++;
        }
        return s;
    }
};
