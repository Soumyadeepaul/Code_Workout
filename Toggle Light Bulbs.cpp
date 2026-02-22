//https://leetcode.com/problems/toggle-light-bulbs/description/


class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        set<int> r;
        unordered_map<int,int> map;
        for(int i:bulbs) map[i]=!map[i];

        for(auto i:map){
            if(i.second==1) r.insert(i.first);
        }
        vector<int> result(r.begin(),r.end());
        return result;
    }
};
