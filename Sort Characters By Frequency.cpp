//https://leetcode.com/problems/sort-characters-by-frequency/description/


class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(char c:s) freq[c]++;
        vector<pair<int,int>> map;
        for(auto p:freq) map.push_back({p.second,p.first});
        sort(map.begin(),map.end(),greater<pair<int, int>>());
        string result="";
        for(auto p:map){
            result+=string(p.first,p.second);
        }
        return result;
    }
};
