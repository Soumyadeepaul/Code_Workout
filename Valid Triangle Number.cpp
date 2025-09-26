//https://leetcode.com/problems/valid-triangle-number/?envType=daily-question&envId=2025-09-26


class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // int l=nums.size();
        // int count=0;
        // for(int i=0;i<l;i++){
        //     for(int j=i+1;j<l;j++){
        //         for(int k=j+1;k<l;k++){
        //             int min1=min(nums[i],min(nums[j],nums[k]));
        //             int max1=max(nums[i],max(nums[j],nums[k]));
        //             int min2=nums[i]+nums[j]+nums[k]-min1-max1;
        //             if(min1+min2>max1){
        //                 count++;
        //             }
        //         }
        //     }
        // }
        // return count;

        sort(nums.begin(),nums.end());
        int l=nums.size();
        int count=0;
        for(int i=0;i<l;i++){
            for(int j=i+1;j<l;j++){
                for(int k=l-1;ACk>j;k--){
                    if(nums[i]+nums[j]>nums[k]){
                        count+=k-j;
                        break;
                    }
                }
            }
        }
        return count;
    }
};
