//https://leetcode.com/problems/find-triangular-sum-of-an-array/?envType=daily-question&envId=2025-09-30

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int i;
        int l=nums.size();
        vector<int> new1;
        while(l!=1){
            i=0;
            for(;i<l-1;i++){
                new1.push_back((nums[i]+nums[i+1])%10);
            }
            nums=new1;
            new1.clear();
            l--;
        }
        return nums[0];
    }
};
