//https://leetcode.com/problems/check-if-array-is-good/description/?envType=daily-question&envId=2026-05-14


class Solution {
public:
    bool isGood(vector<int>& nums) {
        int length=nums.size();
        vector<int> track(length+1,0);
        for(int i:nums){
            if(i>=length) return false;
            if(!track[i]) track[i]=1;
            else if(i==(length-1) && track[i]==1) track[i]=2;
            else return false;
        }
        if(track[length-1]!=2) return false;
        return true;
    }
};
