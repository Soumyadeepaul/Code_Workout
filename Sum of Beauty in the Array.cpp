//https://leetcode.com/problems/sum-of-beauty-in-the-array/

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        vector<int> suffix(nums.size(),0);
        suffix[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>-1;i--){
            suffix[i]=min(nums[i],suffix[i+1]);
        }
        int result=0;
        int prevMax=nums[0];
        for(int i=1;i<nums.size()-1;i++){
            if(prevMax<nums[i]){
                if(suffix[i+1]>nums[i]){
                    result+=2;
                }
                else{
                    if(nums[i]<nums[i+1]){
                        result+=1;
                    }
                }
            }
            else if(nums[i-1]<nums[i] && nums[i]<nums[i+1]){
                result+=1;
            }
            prevMax=max(prevMax,nums[i]);
        }
        return result;
    }
};
