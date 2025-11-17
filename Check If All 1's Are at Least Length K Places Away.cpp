//https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/description/?envType=daily-question&envId=2025-11-17


class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int previous=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                if(previous==-1) previous=i;
                else{
                    if(i-previous-1<k) return false;
                    previous=i;
                }
            }
        }
        return true;
    }
};
