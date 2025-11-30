//https://leetcode.com/contest/weekly-contest-478/problems/maximum-substrings-with-distinct-start/description/


class Solution {
public:
    int maxDistinct(string s) {
        int count=0,l=s.size();
        unordered_set<char> unique;
        for(int i=0;i<l;i++){
            if(unique.find(s[i])==unique.end()){
                count++;
                unique.insert(s[i]);
            }
        }
        return count;
    }
};
