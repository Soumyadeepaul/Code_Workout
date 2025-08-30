//https://leetcode.com/problems/remove-duplicate-letters/description/?envType=problem-list-v2&envId=greedy

//TLE
class Solution {
public:
    void dup(string &s,int index,int l,vector<string> &store,string stack,string &result,vector<int> &present){
        if(find(store.begin(),store.end(),stack)!=store.end()){ //found previously
            return;
        }
        if(index==l){
            if(result.size()<=stack.size()){
                if(result==""){
                    result=stack;
                }
                else if(stack<result){
                    result=stack;
                }
            }
            return;
        }
        
        int ascii=s[index];
        ascii=ascii-97;
        int inserted=0;
        if(present[ascii]==0){//not in string(stack)
            stack=stack+s[index];
            present[ascii]=1;
            inserted=1;
            dup(s,index+1,l,store,stack,result,present);
        }
        

        if(inserted==1){
            stack.pop_back();
            present[ascii]=0;
            inserted=0;
        }
        dup(s,index+1,l,store,stack,result,present);
        store.push_back(stack); // dont duplicate the recursion i.e for bcaca.... there will be 2 bca
        return;
    }
    string removeDuplicateLetters(string s) {
        int l=s.size();
        vector<string> store;
        string stack;
        string result="";
        vector<int> present(26,0); // to check already present in string or not
        dup(s,0,l,store,stack,result,present);
        return result;
    }
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//monotonic increating stack... with frequency count for if present in future or not... and present means to check wheather the alphabate is used in stack or not
//if s[i]<top()...... start poping till s[i]>top() and frequency much be >0 means also present in right side...
//if the alphabate is already used.. dont use it
// always decrement the s[i] frequency by 1
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> frequency;
        unordered_map<char,int> present;
        for(int i=0;i<s.size();i++){
            frequency[s[i]]=frequency[s[i]]+1;
            present[s[i]]=0;
        }

        stack<char> monotonicIncreatingStack;
        string result;
        for(int i=0;i<s.size();i++){
            if(present[s[i]]==1){ //already in stack
                frequency[s[i]]=frequency[s[i]]-1;
            }
            else if(monotonicIncreatingStack.empty() || monotonicIncreatingStack.top()<s[i]){
                monotonicIncreatingStack.push(s[i]);
                frequency[s[i]]=frequency[s[i]]-1;
                present[s[i]]=1;
            }
            else{
                while (!monotonicIncreatingStack.empty()){
                    char val=monotonicIncreatingStack.top();
                    if(frequency[val]>0 && val>s[i]){//char present in future and decreasing formation
                        monotonicIncreatingStack.pop();
                        present[val]=0;
                    }
                    else{
                        break;
                    }
                    
                }
                monotonicIncreatingStack.push(s[i]);
                frequency[s[i]]=frequency[s[i]]-1;
                present[s[i]]=1;
            }

        }
        while (!monotonicIncreatingStack.empty()){
            result=monotonicIncreatingStack.top()+result;
            monotonicIncreatingStack.pop();
        }
        return result;
        

    }
};
