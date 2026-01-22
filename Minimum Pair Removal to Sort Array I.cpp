//https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/description/?envType=daily-question&envId=2026-01-22


class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int result=0;
        while(true){
            int mini=INT_MAX;
            int idx=-1;
            bool descending=true;
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]+nums[i+1]<mini){
                    mini=nums[i]+nums[i+1];
                    idx=i;
                }
                if(nums[i]>nums[i+1]) descending=false;
            }
            if(descending==true) break;
            
            int summ=nums[idx]+nums[idx+1];
            nums.erase(nums.begin()+idx+1);
            nums.erase(nums.begin()+idx);
            nums.insert(nums.begin()+idx,summ);
            result++;
        }
        return result;
    }
};
