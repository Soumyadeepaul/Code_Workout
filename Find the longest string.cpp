//https://www.geeksforgeeks.org/problems/find-the-longest-string--170645/1

//TLE


class Solution {
  public:
    string longestString(vector<string> &words) {
        unordered_set<string> uniq(words.begin(),words.end());
        string result="";
        for(int i=0;i<words.size();i++) {
            string pref;
            bool found=1;
            for(char c:words[i]){
                pref+=string(1,c);
                if(!uniq.count(pref)) {
                    found=0;
                    break;
                }
            }
            if(found==1) {
                if(result.size()<pref.size()) result=pref;
                else if(result.size()==pref.size() && result>pref) result=pref;
            }
        }
        return result;
    }
};

//////////////////////////////////////////////////


struct Node{
    Node* child[26];
    bool end=false;
};
class Solution {
  public:
    string longestString(vector<string> &words) {
        Node* root=new Node();
        
        Node* curr=root;
        
        for(string w:words){
            curr=root;
            for(char c:w){
                int idx=c-'a';
                if(curr->child[idx]==NULL){
                    //create node
                    Node* node=new Node();
                    curr->child[idx]=node;
                }
                curr=curr->child[idx];
            }
            curr->end=true;
        }
        
        
        string result="";
        
        for(string w:words){
            curr=root;
            bool found=1;
            for(char c:w){
                int idx=c-'a';
                if(curr->child[idx]==NULL){
                    found=0;
                    break;
                }
                if(curr->child[idx]->end!=true){ // means there is a word which ends here
                    found=0;
                    break;
                }
                curr=curr->child[idx];
            }
            if(found==1){
                if(result.size()<w.size()) result=w;
                else if(result.size()==w.size() && result>w) result=w;
            }
        }
        return result;
    }
};
