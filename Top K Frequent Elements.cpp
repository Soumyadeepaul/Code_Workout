//https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int i:nums){
            map[i]++;
        }
        //reverse it
        unordered_map<int,vector<int>> map2;
        vector<int> frequency;
        for(auto &pair:map){
            map2[pair.second].push_back(pair.first);
            frequency.push_back(pair.second);
        }
        make_heap(frequency.begin(),frequency.end());
        vector<int> result;
        int size=0;
        int maxi;
        while (size!=k){
            maxi=frequency.front();
            result.push_back(map2[maxi].back());
            map2[maxi].pop_back();
            pop_heap(frequency.begin(),frequency.end());
            frequency.pop_back();
            size++;
        }
        return result;
    }
};
