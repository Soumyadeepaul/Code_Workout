//https://leetcode.com/problems/arithmetic-slices/?envType=problem-list-v2&envId=sliding-window



class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int count=0;
        int i=0,j=2,l=nums.size();
        if(l<2) return 0;
        int prev=nums[1];
        int diff=nums[1]-nums[0];
        int previousCount=0;
        while(j<l){
            if(nums[j]-prev==diff){
                if(j-i>=2){
                    int n=j-i-1;
                    count=previousCount+(n*(n+1)/2);
                }
                prev=nums[j];
                j++;
            }
            else{
                prev=nums[j-1];
                i=j-1;
                diff=nums[j]-prev;
                previousCount=count;
            }
        }
        return count;
    }
};
