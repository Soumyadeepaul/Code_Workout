//https://leetcode.com/problems/largest-divisible-subset/description/


class Solution {
public:
    unordered_map<int, vector<int>> map;
    vector<int> helper(vector<int> &nums, int idx){
        if(idx==nums.size()) return {};
        if(map.count(nums[idx])) return map[nums[idx]];
        vector<int> store;
        vector<int> addon;
        helper(nums,idx+1);
        for(int i=idx+1;i<nums.size();i++){
            if(nums[i]%nums[idx]==0){
                store=helper(nums,i);
                if(addon.size()<store.size()) addon=store;
            }
        }
        map[nums[idx]].push_back(nums[idx]);
        for(int i:addon) map[nums[idx]].push_back(i);

        return map[nums[idx]];
    } 
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        helper(nums,0);
        vector<int> result;
        for(auto p:map){
            if(result.size()<p.second.size()) result=p.second;
        }
        return result;
    }
};
