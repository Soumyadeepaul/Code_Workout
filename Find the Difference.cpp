//https://leetcode.com/problems/find-the-difference/?envType=problem-list-v2&envId=hash-table

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<int,int> hashmap={};
        for(int i=0;i<s.length();i++){
            if(hashmap.find(s[i])!=hashmap.end()){
                hashmap[s[i]]=hashmap[s[i]]+1;
            }
            else{
                hashmap.insert({s[i],1});
            }
        }
        for(int i=0;i<t.length();i++){
            if(hashmap.find(t[i])!=hashmap.end()){
                if(hashmap[t[i]]==0){
                    return t[i];
                }
                hashmap[t[i]]=hashmap[t[i]]-1;
            }
            else{
                return t[i];
            }
        }
        return ' ';
    }
};
