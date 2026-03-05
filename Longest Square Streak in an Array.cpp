//https://leetcode.com/problems/longest-square-streak-in-an-array/description/


class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<long long,int> map;
        for(int i:nums) map[i]=0;
        int result=-1;
        for(int i=nums.size()-1;i>-1;i--){
            map[nums[i]]=map[1ll*nums[i]*nums[i]]+1;
            result=max(result,map[nums[i]]);
        }
        return (result==1) ? -1:result;
    }
};
