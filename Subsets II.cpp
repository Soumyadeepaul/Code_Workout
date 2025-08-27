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

////////////////////////////
class Solution {
public:
    void subset(vector<int>&nums,vector<vector<int>> &result, int index, vector<int> bucket,int l){
        result.push_back(bucket);
        for(int i=index;i<l;i++){
            if(i!=index && nums[i]==nums[i-1]){ //not that same index and also same as previous element -> duplicate  
                //not that same index and also same as previous element -> duplicate...... i!=index means... atleast once the element will enter
                continue;
            }
            bucket.push_back(nums[i]);
            subset(nums,result,i+1,bucket,l);
            bucket.pop_back();
        }
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
