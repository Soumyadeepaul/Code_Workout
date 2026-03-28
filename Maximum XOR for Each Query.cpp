//https://leetcode.com/problems/maximum-xor-for-each-query/


class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        
        vector<int> result;
        int xorr=0, maxorr=pow(2,maximumBit)-1;
        for(int i:nums){
            xorr^=i;
        }
        for(int i=0;i<nums.size();i++){
            result.emplace_back(xorr^maxorr);
            xorr^=nums[nums.size()-i-1];
        }
        return result;
    }
};
