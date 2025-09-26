//https://leetcode.com/problems/permutations-ii/

class Solution {
public:
    void permute(vector<vector<int>>&result,vector<int> nums,int idx,int &l){
        if(idx==l-1){
            result.push_back(nums);
            return;
        }
        for(int i=idx;i<l;i++){
            // idx not same but value same... no backtracking and dont use &nums
            if (i != idx && nums[i] == nums[idx]) continue;
            swap(nums[i],nums[idx]);
            permute(result,nums,idx+1,l);
            //swap(nums[i],nums[idx]);
        
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        int l=nums.size();
        sort(nums.begin(),nums.end());
        permute(result,nums,0,l);
        return result;
    }
};
