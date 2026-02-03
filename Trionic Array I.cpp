//https://leetcode.com/problems/trionic-array-i/description/?envType=daily-question&envId=2026-02-03

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int count=0;
        int i=1;
        bool flow=0; //0 increase 1 decrease
        while(i<nums.size()){
            if(nums[i]<=nums[i-1] && i-1==0) return false;
            if(nums[i]==nums[i-1]) return false;
            if(nums[i]>nums[i-1] && flow==0){
                i++;
            }
            else if(nums[i]>nums[i-1] && flow==1){
                i++;
                count++;
                flow=0;
            }
            else if(nums[i]<nums[i-1] && flow==0){
                i++;
                count++;
                flow=1;
            }
            else{
                i++;
            }

            if(count==3) return false;
        }
        if(count==2) return true;
        return false;
    }
};
