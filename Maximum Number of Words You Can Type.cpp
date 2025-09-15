//https://leetcode.com/problems/maximum-number-of-words-you-can-type/description/?envType=daily-question&envId=2025-09-15


class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> malf;
        for(int i=0;i<brokenLetters.size();i++){
            malf.insert(brokenLetters[i]);
        }
        int count=0;
        bool word=true;
        text=text+" ";
        for(int i=0;i<text.size();i++){
            if(text[i]==' '){
                if (word==true) count++;
                word=true;
            }
            else{
                if(word==true){
                    if(find(malf.begin(),malf.end(),text[i])!=malf.end()){
                        word=false;
                    }
                }
            }
        }
        return count;
    }
};
