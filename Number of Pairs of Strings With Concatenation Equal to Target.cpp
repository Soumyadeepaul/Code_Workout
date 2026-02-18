//https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/description/


class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int result=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size() && i!=j ; j++){
                if(nums[i]+nums[j]==target) result++;
                if(nums[j]+nums[i]==target) result++;
            }
        }
        return result;
    }
};
