//https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/description/?envType=daily-question&envId=2025-10-13


class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        unordered_map<char,int> prev;
        unordered_map<char,int> map;
        for(string i:words){
            for(char j:i){
                map[j]++;
            }
            if(map!=prev){
                prev=map;
                result.push_back(i);
            }
            map.clear();
        }
        return result;

    }
};
