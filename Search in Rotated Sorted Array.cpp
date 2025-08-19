//https://leetcode.com/problems/search-in-rotated-sorted-array/description/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot;
        int start=1;
        int end=nums.size()-2;
        int mid;
        int l= nums.size();
        if(l==2){
            if(nums[0]>nums[1]){
                pivot=1;
            }
            else{
                pivot=0;
            }
        }
        else if(nums[0]<=nums[l-1]){
            pivot=0;
        }
        else{
            while(start<=end){
                mid=start+(end-start)/2;
                if(nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1]){
                    if(nums[mid]>nums[0]){
                        start=mid+1;
                    }
                    else{
                        end=mid-1;
                    }
                }
                else{
                    if(nums[mid]<nums[mid+1] && nums[mid]<nums[mid-1]){
                        pivot=mid;
                    }
                    else if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
                        pivot=mid+1;
                    }
                    
                    break;
                }
            }
        }

        // return pivot;
        if(nums[pivot]==target){
            return pivot;
        }
        else if(nums[pivot]<target){
            if(target>nums[l-1]){
                //bs left of pivot
                int s=0;
                int e=pivot-1;
                int m;
                while (s<=e){
                    m=s+(e-s)/2;
                    if(nums[m]==target){
                        return m;
                    }
                    else if(nums[m]>target){
                        e=m-1;
                    }
                    else{
                        s=m+1;
                    }
                }
                return -1;
            }
            else{
                //bs right of pivot
                int s=pivot+1;
                int e=l-1;
                int m;
                while (s<=e){
                    m=s+(e-s)/2;
                    if(nums[m]==target){
                        return m;
                    }
                    else if(nums[m]>target){
                        e=m-1;
                    }
                    else{
                        s=m+1;
                    }
                }
                return -1;
            }
        }
        else{
            return -1;
        }
    }
};
