//https://leetcode.com/problems/peak-index-in-a-mountain-array/description/?envType=study-plan-v2&envId=binary-search


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start=1;
        int end=arr.size();
        int mid;
        while(start<=end){
            mid=start+(end-start)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                return mid;
            }
            else if(arr[mid]>arr[mid-1]&& arr[mid]<arr[mid+1]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return 0;
    }
};
