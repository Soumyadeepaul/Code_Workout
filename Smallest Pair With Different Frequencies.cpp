//https://leetcode.com/contest/biweekly-contest-177/problems/smallest-pair-with-different-frequencies/description/


class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i:nums) map[i]++;
        vector<vector<int>> p;
        for(auto i:map) p.push_back({i.first,i.second});
        sort(p.begin(),p.end());
        for(int i=0;i<p.size();i++){
            for(int j=i+1;j<p.size();j++){
                if(p[i][1]!=p[j][1]) return {p[i][0],p[j][0]};
            }
        }
        return {-1,-1};
    }
};
