// https://leetcode.com/problems/first-missing-positive/description/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int l=nums.size();
        for(int i=0;i<l;i++){
            if(nums[i]<0) nums[i]=0;//all negetive to 0
        }
        for(int i=0;i<l;i++){

            if(nums[i]==0){}
            else if(abs(nums[i])>l){}
            else{
                if(nums[abs(nums[i])-1]==0) nums[abs(nums[i])-1]=-l-1;// if zero replace with -(l+1)
                else
                    nums[abs(nums[i])-1]=-abs(nums[abs(nums[i])-1]);//else change the val to -... but while checking for that index take abs
            }
        }
        int i=0;
        for(;i<l;i++){
            if(nums[i]>=0) break;
        }
        return i+1;
    }
};
