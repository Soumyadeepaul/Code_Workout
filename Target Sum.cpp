//https://leetcode.com/problems/target-sum/solutions/7185860/c-intuition-is-s1-s2d-by-paulsoumyadeep7-wbke/

class Solution {
public:
// intuition -> convert 2 subsets... s1 - s2
    void subset(vector<int> &nums,int &target,int i, int &l,int &summ,int &result,int &stack){
        if(stack-summ==target)
        {            
            result++;

        }
        for(;i<l;i++){
            stack+=nums[i];
            summ-=nums[i];
            subset(nums,target,i+1,l,summ,result,stack);
            stack-=nums[i];
            summ+=nums[i];
        }
        return;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int l=nums.size();
        int summ=accumulate(nums.begin(),nums.end(),0);
        int result=0;
        int stack=0;
        subset(nums,target,0,l,summ,result,stack);
        return result;
    }
};
