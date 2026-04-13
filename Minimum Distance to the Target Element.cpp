//https://leetcode.com/problems/minimum-distance-to-the-target-element/description/?envType=daily-question&envId=2026-04-13


class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int i=start,j=start;
        while(i>-1 && j<nums.size()){
            if(nums[i]==target) return abs(i-start);
            if(nums[j]==target) return abs(j-start);
            i--;
            j++;
        }
        while(i!=-1){
            if(nums[i]==target) return abs(i-start);
            i--;
        }
        while(j!=nums.size()){
            if(nums[j]==target) return abs(j-start);
            j++;
        }
        return 0;
    }
};
