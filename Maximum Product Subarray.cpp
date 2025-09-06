//https://leetcode.com/problems/maximum-product-subarray/description/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //start from left and right
        // if encounter with 0... set to 1
        // take max of left and right and previous max..
        //[-2,0,-1] for such cases... when left or right value will turn to 1 becoz of 0
        // bu multiplication out there is not 1... its 0... so use of left=1.. but mul =0


        // int left=0;
        int result=INT_MIN;
        int size=nums.size();
        int right=size-1;
        int mulLeft=1;
        int mulRight=1;
        int max2;
        int leftVal=0;
        int rightVal=0;
        for(int i=0;i<size;i++){
            if(nums[i]==0) {
                mulLeft=1;
                leftVal=0;
            }
            else{
                mulLeft=mulLeft*nums[i];
                leftVal=mulLeft;
            }
            if(nums[right-i]==0) {
                mulRight=1;
                rightVal=0;
            }
            else{
                mulRight=mulRight*nums[right-i];
                rightVal=mulRight;
            }
            max2=max(rightVal,leftVal);
            result=max(result,max2);
        }
        return result;
    }
};
