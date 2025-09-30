//https://leetcode.com/problems/palindrome-partitioning/description/


class Solution {
public:
    bool isPalin(string &s, int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]){return false;}
        }
        return true;
    }
    void create(string &s, int idx,int &l,vector<vector<string>>& result,vector<string> path){
        if(idx==l){
            result.push_back(path);
            return;
        }
        for(int i=idx;i<l;i++){
            if(isPalin(s,idx,i)){
                path.push_back(s.substr(idx,i-idx+1));//
                create(s,i+1,l,result,path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int index=0;
        vector<vector<string>> result;
        int l=s.size();
        vector<string> path;
        create(s,0,l,result,path);
        return result;
    }
};
