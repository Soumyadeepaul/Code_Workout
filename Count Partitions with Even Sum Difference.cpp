//https://leetcode.com/problems/count-partitions-with-even-sum-difference/description/?envType=daily-question&envId=2025-12-05


class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int count=0;
        int total=accumulate(nums.begin(),nums.end(),0);
        int left=0;
        for(int i=0;i<nums.size()-1;i++){
            total-=nums[i];
            left+=nums[i];
            if(abs(total-left)&1){}
            else count++;
        }   
        return count;
    }
};
