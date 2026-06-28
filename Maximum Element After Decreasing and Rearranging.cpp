//https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/description/?envType=daily-question&envId=2026-06-28


class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int i=0;
        arr[i]=1;
        int maxi=1;
        i++;
        while(i<arr.size()){
            if(arr[i]-arr[i-1]>1) arr[i]=arr[i-1]+1;
            maxi=max(maxi,arr[i]);
            i++;
        }
        return maxi;
    }
};
