//https://leetcode.com/problems/make-array-elements-equal-to-zero/?envType=daily-question&envId=2025-10-28


class Solution {
public:
    bool helper(vector<int> nums,int &i,int direct){
        int idx=i;
        int direction=direct; // left=-1   right 1
        idx=idx+direction;
        while(idx>-1 && idx<nums.size()){
            if(nums[idx]>0){
                nums[idx]--;
                if(direction==-1)
                    direction=1;
                else direction=-1;
            }
            idx=idx+direction;
        }
        for(int j=0;j<nums.size();j++){
            if(nums[j]!=0) return false;
        }
        return true;
    }
    int countValidSelections(vector<int>& nums) {
        
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0 && helper(nums,i,-1)) count++;
            if(nums[i]==0 && helper(nums,i,1)) count++;
        }
        return count;
    }
};
