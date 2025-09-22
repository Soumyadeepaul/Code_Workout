//https://leetcode.com/problems/sort-colors/description/


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int temp=0;
        while(temp<=j){
            if(nums[temp]==0){
                swap(nums[i],nums[temp]);
                i++;
                temp++;
            }
            else if(nums[temp]==2){
                swap(nums[j],nums[temp]);
                j--;
            }
            else{
                temp++;
            }
        }
    }
};
