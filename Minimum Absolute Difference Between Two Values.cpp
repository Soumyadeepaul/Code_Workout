//https://leetcode.com/contest/biweekly-contest-179/problems/minimum-absolute-difference-between-two-values/description/



class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int result=1e9;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) continue;
            int j=i+1;
            while(j<nums.size()){
                if(nums[i]==1 && nums[j]==2){
                    result=min(result,abs(i-j));
                    break;
                }
                else if(nums[i]==2 && nums[j]==1){
                    result=min(result,abs(i-j));
                    break;
                }
                j++;
            }
        }
        
        return (result==1e9)? -1: result;
    }
};
