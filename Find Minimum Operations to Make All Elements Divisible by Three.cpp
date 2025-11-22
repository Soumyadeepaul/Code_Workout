//https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/description/?envType=daily-question&envId=2025-11-22

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int result=nums.size();
        for(int i:nums){
            if(i%3==0) result--;
        }
        return result;
    }
};
