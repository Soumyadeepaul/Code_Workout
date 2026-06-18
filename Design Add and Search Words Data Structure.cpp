//https://leetcode.com/problems/design-add-and-search-words-data-structure/description/?envType=study-plan-v2&envId=top-interview-150


struct Trie{
    unordered_map<char,Trie*> alpha;
    bool end=false;
};
class Insert{
    public:
    Insert(Trie* parent, string word){

        for(char c:word){
            if(!parent->alpha.count(c)){
                Trie* node= new Trie();
                parent->alpha[c]=node;
            }
            parent=parent->alpha[c];
        }
        parent->end=true;
    }
    virtual ~Insert(){};
};

class Search{
    public:
    bool src(Trie* parent, string &word, int idx){
        
        if(idx==word.size()){
            return parent->end;
        }

        if(word[idx]=='.'){
            for(auto p: parent->alpha){
                if(src(parent->alpha[p.first],word,idx+1)) return true;
            }
        }
        else if(parent->alpha.count(word[idx])){
            return src(parent->alpha[word[idx]],word,idx+1);
        }
        return false;
    }
};

class WordDictionary {
public:
    Trie* root;
    Search src;
    WordDictionary() {
        root=new Trie();
    }
    
    void addWord(string word) {
        Insert* i= new Insert(root,word);
        delete i;
    }
    
    bool search(string word) {
        return src.src(root,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
