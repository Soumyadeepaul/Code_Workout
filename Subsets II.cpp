//https://leetcode.com/problems/subsets-ii/description/

class Solution {
public:
    void subset(vector<int>&nums,vector<vector<int>> &result, int index, vector<int> bucket,int l){
        if(index==l){
            if(find(result.begin(),result.end(),bucket)==result.end()){
                result.push_back(bucket);
            }
            return;
        }
        bucket.push_back(nums[index]);
        subset(nums,result,index+1,bucket,l);
        bucket.pop_back();
        subset(nums,result,index+1,bucket,l);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> bucket;
        int l=nums.size();
        subset(nums,result,0,bucket,l);
        return result;
    }
};
