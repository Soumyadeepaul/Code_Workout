//https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/description/?envType=daily-question&envId=2026-02-01


class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int first=nums[0];
        int second=min(nums[1],nums[2]);
        int third=max(nums[2],nums[1]);
        for(int i=3;i<nums.size();i++){
            if(third>nums[i]) third=nums[i];
            else if(second>nums[i]) second=nums[i];
            int temp1=max(third,second);
            int temp2=min(third,second);
            second=temp2;
            third=temp1;
        }
        return first+second+third;
    }
};
