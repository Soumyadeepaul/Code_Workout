//https://leetcode.com/problems/house-robber-ii/?envType=problem-list-v2&envId=array


class Solution {
public:
    int rob(vector<int>& nums) {
        int maxi=0;
        int l=nums.size();
        if(l<=2) return *max_element(nums.begin(),nums.end());
        //taking from 1st house and not taking from last house
        vector<int> dp1(l,0);
        dp1[0]=nums[0];
        dp1[1]=max(nums[0],nums[1]);
        for(int i=2;i<l-1;i++){
            dp1[i]=max(dp1[i-1],nums[i]+dp1[i-2]);
            // cout<<dp1[i]<<" ";
        }
        // cout<<"\n";
        //taking from last house and not taking from 1st house
        vector<int> dp2(l,0);
        dp2[1]=nums[1];
        for(int i=2;i<l;i++){
            dp2[i]=max(dp2[i-1],nums[i]+dp2[i-2]);
            // cout<<dp2[i]<<" ";
        }
        return max(dp1[l-2],dp2[l-1]);
    }
};
