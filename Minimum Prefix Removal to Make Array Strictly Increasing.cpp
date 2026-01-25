//https://leetcode.com/contest/weekly-contest-486/problems/minimum-prefix-removal-to-make-array-strictly-increasing/description/


class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int i=0,j=1,l=nums.size();

        while(j<l){
            if(nums[j]<=nums[j-1]){
                i=j;
            }
            j++;
        }
        return i;
    }
};
