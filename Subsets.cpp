//https://leetcode.com/problems/subsets/description/

class Solution {
public:
    vector<vector<int>> result;
    void helper(vector<int>& nums, vector<int> store, int idx){
        if(idx==nums.size()){
            result.emplace_back(store);
            return;
        }
        //not take
        helper(nums,store,idx+1);
        // take
        store.emplace_back(nums[idx]);
        helper(nums,store,idx+1);
        store.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> store;
        helper(nums,store,0);
        return result;
    }
};
