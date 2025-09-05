//https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int start=0;
        int end=nums.size()-1;
        int mid;
        while(start<=end){
            mid=start+(end-start)/2;
            //cout<<mid<<endl;
            if (mid==0 && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            else if (mid==nums.size()-1 && nums[mid]!=nums[mid-1]){
                return nums[mid];
            }
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            else if(mid&1){// odd
                if(nums[mid]!=nums[mid-1]){
                    end=mid-1;
                }
                else if(nums[mid]==nums[mid-1]){
                    start=mid+1;
                }
            }
            else{//even
                if(nums[mid]==nums[mid+1]){
                    start=mid+2;
                }
                else if(nums[mid]!=nums[mid+1]){
                    end=mid;
                }
            }
        }
        return 0;

    }
};
