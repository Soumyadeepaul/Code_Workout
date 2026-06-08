//https://leetcode.com/problems/count-number-of-nice-subarrays/description/


class Solution {
public:
    int helper(vector<int>& nums, int k){
        int i=0,j=0,l=nums.size();
        int count=0;
        int result=0;
        while(j<l){
            if(nums[j]&1) count++;
            while(i<=j && count>k){
                if(nums[i]&1) count--;
                i++;
            }
            if(count<=k) result+=(j-i+1);
            j++;
        }
        return result;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};
