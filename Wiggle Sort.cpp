//https://www.geeksforgeeks.org/problems/wave-array-1587115621/1


class Solution {
  public:
    void sortInWave(vector<int>& nums) {
        // code here
        for(int i=0;i<nums.size()-1;i++){
            if(i&1) {//odd
                if(nums[i]>nums[i+1]){
                    swap(nums[i],nums[i+1]);
                }
            }
            else{
                if(nums[i]<nums[i+1]){
                    swap(nums[i],nums[i+1]);
                }
            }
        }
    }
};
