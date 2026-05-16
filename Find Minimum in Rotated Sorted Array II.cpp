//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/?envType=daily-question&envId=2026-05-16


class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0, right=nums.size()-1;
        int mid, resultIdx=0;

        while(left<=right){
            while(left<right && nums[left]==nums[left+1]) left++;
            while(right>left && nums[right]==nums[right-1]) right--;
            mid=(left+right)/2;

            if(nums[mid]<nums[resultIdx]){
                resultIdx=mid;
            }
            if(nums[mid]<nums[right]){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return nums[resultIdx];
    }
};
