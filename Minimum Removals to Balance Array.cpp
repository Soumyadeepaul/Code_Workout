//https://leetcode.com/problems/minimum-removals-to-balance-array/description/?envType=daily-question&envId=2026-02-06


class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int i=0,j=0;
        sort(nums.begin(),nums.end());
        int count=INT_MAX;
        int n=nums.size();
        while(j<nums.size()){
            if(nums[j]<=(long long)nums[i]*k){
                count=min(n-(j-i+1),count);
                j++;
            }
            else{
                i++;
            }
        }
        return count;
    }
};
