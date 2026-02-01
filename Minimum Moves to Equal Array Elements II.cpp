//https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/


class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int median=nums[nums.size()/2];

        int total=0;

        for(int i:nums){
            total+=abs(i-median);
        }
        return total;
    }
};
