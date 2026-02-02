//https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/description/


class Solution {
public:
    int check(vector<int> &nums, int i, int k){
        int j;
        for(j=i+1;j<i+k;j++){
            if(nums[j]-nums[j-1]!=1) return j;
        }
        return j;
    }
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> result;
        int i=0;
        while(i+k-1<nums.size()){
            int idx=check(nums,i,k);
            if(idx==i+k){
                result.push_back(nums[i+k-1]);
                i++;
            }
            else{
                while(i<idx){
                    result.push_back(-1);
                    i++;
                }
            }
        }
        vector<int> r(result.begin(),result.begin()+(nums.size()-k+1));
        return r;

    }
};
