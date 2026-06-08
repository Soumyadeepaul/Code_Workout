//https://leetcode.com/problems/binary-subarrays-with-sum/description/

class Solution {
public:
    int helper(vector<int>& nums, int goal){ //return number of subarray where summ<=goal
        if(goal<0) return 0;
        int i=0,j=0,l=nums.size();
        int summ=0;
        int count=0;

        while(j<l){
            summ+=nums[j];
            while(i<=j && summ>goal){
                summ-=nums[i];
                i++;
            }
            count=count+(j-i+1);
            j++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums,goal)-helper(nums,goal-1);
    }
};
