//https://leetcode.com/problems/longest-balanced-substring-i/description/?envType=daily-question&envId=2026-02-12


class Solution {
public:
    bool check(unordered_map<char,int> &map){
        int c=-1;
        for(auto &p:map){
            if(c==-1) c=p.second;
            else{
                if(p.second!=c) return false;
            }
        }
        return true;
    }
    int longestBalanced(string s) {
        int result=0;
        for(int i=0;i<s.size()-result;i++){
            unordered_map<char,int> map;
            pair<int,int> maxi;
            for(int j=i;j<s.size();j++){
                map[s[j]]+=1;
                if(check(map)) result=max(result,j-i+1);
            }
        }
        return result;
    }
};
