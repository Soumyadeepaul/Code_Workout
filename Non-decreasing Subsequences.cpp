//https://leetcode.com/problems/non-decreasing-subsequences/description/?envType=problem-list-v2&envId=hash-table


class Solution {
public:
    void helper(vector<int> &nums,vector<int> stack,int i,vector<vector<int>>&result){
        if(stack.size()>1){
            result.push_back(stack);
        }
        else if(i==nums.size()) return;

        unordered_set<int> same;
        for(int j=i;j<nums.size();j++){
            if((stack.empty() || stack.back()<=nums[j]) && same.find(nums[j])==same.end()){ // same element stores the value already used in forming combination
                stack.push_back(nums[j]);
                same.insert(nums[j]);
                helper(nums,stack,j+1,result);
                stack.pop_back();
            }

        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> stack;
        helper(nums,stack,0,result);
        return result;
    }
};
