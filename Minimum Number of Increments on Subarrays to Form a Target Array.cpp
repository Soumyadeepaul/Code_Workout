//https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/description/?envType=daily-question&envId=2025-10-30


class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int count=target[0];
        for(int i=1;i<target.size();i++){
            if(target[i-1]<target[i]){
                count+=target[i]-target[i-1];
            }
        }
        return count;
    }
};
