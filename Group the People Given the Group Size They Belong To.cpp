//https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<vector<int>>> map;
        for(int i=0;i<groupSizes.size();i++){
            vector<vector<int>> m=map[groupSizes[i]];
            if(m.empty()) map[groupSizes[i]].push_back({i});
            else if(m.back().size()==groupSizes[i]){
                map[groupSizes[i]].push_back({i});
            }
            else{
                map[groupSizes[i]].back().push_back(i);
            }
        }
        vector<vector<int>> result;
        for(auto p:map){
            for(vector<int> p1:p.second)
                result.push_back(p1);
        }
        return result;
    }
};
