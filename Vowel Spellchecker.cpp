//https://leetcode.com/problems/vowel-spellchecker/description/?envType=daily-question&envId=2025-09-14


class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> wordList;
        unordered_map<string,string> map;
        unordered_map<string,string> vowel;
        string s;
        string vow="aeiouAEIOU";
        for(int i=0;i<wordlist.size();i++){
            wordList.insert(wordlist[i]);
            s=wordlist[i];
            transform(s.begin(),s.end(),s.begin(),::tolower);
            if(map.find(s)==map.end()) map[s]=wordlist[i];
            
            for(int i=0;i<s.size();i++){
                if(find(vow.begin(),vow.end(),s[i])!=vow.end()){
                    s[i]='*';
                }
            }
            if(vowel.find(s)==vowel.end())
                vowel[s]=wordlist[i];
            
        }
        for(int i=0;i<queries.size();i++){
            if(find(wordList.begin(),wordList.end(),queries[i])==wordList.end()){
                s=queries[i];
                transform(s.begin(),s.end(),s.begin(),::tolower);
                if(map.find(s)!=map.end()){
                    queries[i]=map[s];
                }
                else{
                    for(int i=0;i<s.size();i++){
                        if(find(vow.begin(),vow.end(),s[i])!=vow.end()){
                            s[i]='*';
                        }
                    }
                    queries[i]=vowel[s];
                }
            }
        }
        return queries;
    }
};
