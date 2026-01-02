//https://leetcode.com/problems/n-repeated-element-in-size-2n-array/description/?envType=daily-question&envId=2026-01-02

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> map;
        int l=nums.size()/2;
        for(int i:nums){
            map[i]++;
            if(map[i]==l) return i;
        }
        return 0;
    }
};
