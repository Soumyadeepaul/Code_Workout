//https://leetcode.com/problems/two-sum/description/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> search;
        vector<int> result;
        int valToFind;
        for(int i=0;i<nums.size();i++){
            valToFind=target-nums[i];
            auto find=search.find(valToFind);
            if(find!=search.end()){
                result.push_back(search[valToFind]);
                result.push_back(i);
                break;
            }
            search.insert({nums[i],i});
        }
        return result;
    }
};
