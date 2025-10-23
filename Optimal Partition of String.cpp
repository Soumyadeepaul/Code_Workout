//https://leetcode.com/problems/optimal-partition-of-string/description/


class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> map;
        int i=0;
        int count=0;
        while(i<s.size()){
            if(map.find(s[i])==map.end()){
                map.insert(s[i]);
            }
            else{
                count++;
                map.clear();
                map.insert(s[i]);
            }
            i++;
        }
        count++;
        return count;
    }
};
