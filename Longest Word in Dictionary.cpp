//https://leetcode.com/problems/longest-word-in-dictionary/description/?envType=problem-list-v2&envId=trie



struct Trie{
    unordered_map<char, Trie*> data;
    int end=-1;
};
class Solution {
public:
    bool create(string word, Trie* parent){
        int l=word.size();

        for(int i=0;i<l;i++){
            if(parent->data.count(word[i])){ //already available
                parent=parent->data[word[i]];
            }
            else if(i==l-1){ //last character
                Trie* node= new Trie();
                node->end=1;
                parent->data[word[i]]=node;
            }
            else return false;
        }
        return true;
    }
    string longestWord(vector<string>& words) {
        // trie build, insert a new node only if its the last character
        sort(words.begin(),words.end());
        string result="";
        Trie* root=new Trie();
        for(auto word:words) {
            if(create(word, root)){
                if(result.size()<word.size()) result=word;
            }
        }
        return result;
    }
};
