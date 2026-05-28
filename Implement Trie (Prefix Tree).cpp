//https://leetcode.com/problems/implement-trie-prefix-tree/description/


struct Node{
    Node * child[26];
    bool end=false;
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* curr=root;
        for(char c:word){
            int idx=c-'a';
            if(curr->child[idx]==NULL){
                //create new
                Node* node=new Node();
                curr->child[idx]=node;
            }
            curr=curr->child[idx];
        }
        curr->end=true;
    }
    
    bool search(string word) {
        Node* curr=root;
        for(char c:word){
            int idx=c-'a';
            if(curr->child[idx]==NULL){
                return false;
            }
            curr=curr->child[idx];
        }

        return curr->end;
    }
    
    bool startsWith(string prefix) {
        Node* curr=root;
        for(char c:prefix){
            int idx=c-'a';
            if(curr->child[idx]==NULL){
                return false;
            }
            curr=curr->child[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
