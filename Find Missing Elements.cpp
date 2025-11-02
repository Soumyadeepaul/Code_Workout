//https://leetcode.com/contest/weekly-contest-474/problems/find-missing-elements/description/


class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> result;
        int s=nums[0];
        int l=nums[nums.size()-1];
        int idx=0;
        for(int i=s;i<=l;i++){
            if(nums[idx]==i){
                idx++;
            }
            else{
                result.push_back(i);
            }
        }
        return result;
    }
};©leetcode
