//https://leetcode.com/problems/longest-balanced-subarray-i/description/?envType=daily-question&envId=2026-02-10

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int i=0,j=0,l=nums.size();
        int result=0;
        for(;i<l;i++){
            unordered_map<int,int> even,odd;
            for(j=i;j<l;j++){
                if(nums[j]&1) odd[nums[j]]+=1;
                else even[nums[j]]+=1;
                if(odd.size()==even.size()) result=max(result,j-i+1);
            }
        }
        return result;
    }
};
