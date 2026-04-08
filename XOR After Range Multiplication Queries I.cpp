//https://leetcode.com/problems/xor-after-range-multiplication-queries-i/description/?envType=daily-question&envId=2026-04-08


class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod=1e9+7;
        for(vector<int> q:queries){
            for(int i=q[0];i<=q[1];){
                nums[i]=(1ll*nums[i]*q[3])%mod;
                i+=q[2];
            }
        }
        for(int i=1;i<nums.size();i++){
            nums[i]^=nums[i-1];
        }
        return nums[nums.size()-1];
    }
};
