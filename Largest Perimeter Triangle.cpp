//https://leetcode.com/problems/largest-perimeter-triangle/description/?envType=daily-question&envId=2025-09-28


class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        // sum if 2 smaller side > larger side
        sort(nums.begin(),nums.end(),greater<int>());
        int maxiArea=0;
        int l=nums.size();
        for(int i=0;i<l;i++){
            for(int j=i+1;j<l;j++){
                for(int k=j+1;k<l;k++){
                    if(nums[k]+nums[j]>nums[i]){
                        maxiArea=max(maxiArea,nums[i]+nums[j]+nums[k]);
                        return maxiArea;
                    }
                    else break;
                }
            }
        }
        return maxiArea;
    }
};
