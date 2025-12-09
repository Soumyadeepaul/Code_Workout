//https://leetcode.com/problems/count-special-triplets/description/?envType=daily-question&envId=2025-12-09


class Solution {
public:
    // TLE  1101/1121
    // int specialTriplets(vector<int>& nums) {
    //     int count=0,l=nums.size(),mod=pow(10,9)+7;
    //     int target,j,freqK;
    //     for(int i=0;i<l;i++){
    //         if(nums[i]&1) continue;
    //         target=nums[i]/2;
    //         j=l-1;
    //         freqK=0;
    //         while(j>i){
    //             if(nums[j]==target) count=(count+freqK)%mod;
    //             if(nums[j]==nums[i]) freqK++;
    //             j--;
    //         }
    //     }
    //     return count;


        /////////////////////////////
    int specialTriplets(vector<int>& nums) {
        int count=0,l=nums.size(),mod=pow(10,9)+7;
        unordered_map<int,int> left;
        unordered_map<int,int> right;

        for(int n:nums) right[n]++;
        for(int i:nums){
            right[i]--;
            count=(count+((1LL)*left[i<<1]*right[i<<1]))%mod;
            left[i]++;
        }
        return count;
    }
};
