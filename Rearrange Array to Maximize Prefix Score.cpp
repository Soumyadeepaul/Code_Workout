//https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score/description/


class Solution {
public:
    int maxScore(vector<int>& nums) {
        long long result=0;
        sort(nums.begin(),nums.end(),greater<int>());
        int l=nums.size();
        long long ans=0;
        for(int i=0;i<l;i++){
            result+=nums[i];
            if(result>0) ans++;
        }
        return ans;
    }
};
