//https://leetcode.com/problems/find-peak-element/description/


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        if(end==0){
            return 0;
        }
        int mid;
        while (start<=end){
            mid=start+(end-start)/2;
            if(mid-1<0){
                if(nums[mid]>nums[mid+1]){
                    return mid;
                }
                else{
                    return mid+1;
                }
            }
            if(mid+1>=nums.size()){
                if(nums[mid]>nums[mid-1]){
                    return mid;
                }
                else{
                    return mid-1;
                }
            }
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid]>nums[mid-1]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return 0;
    }
};
