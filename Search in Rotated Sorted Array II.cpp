//https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start=0, end=nums.size()-1;
        int mid;
        while(start<=end){
            while(start+1<nums.size() && nums[start]==nums[start+1]) start++;
            while(end-1>-1 && nums[end]==nums[end-1]) end--;
            int mid=(start+end)/2;
            if(nums[mid]==target) return true;
            else if(nums[mid]<nums[end]) {
                // right is sorted
                if(nums[mid]<target && target<=nums[end]) start=mid+1;
                else end=mid-1;
            }
            else{
                //left is sorted
                if(target>=nums[start] && target<nums[mid]) end=mid-1; 
                else start=mid+1; 
            }
        }
        return false;
    }
};
