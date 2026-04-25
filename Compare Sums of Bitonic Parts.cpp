//Compare Sums of Bitonic Parts


class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long unsigned left=nums[0], right=0, peak=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]) left+=nums[i];
            else{
                if(peak==0) peak=nums[i-1];
                right+=nums[i];
            }
        }
        left-=peak;
        if(left>right) return 0;
        else if(right>left) return 1;
        return -1;
    }
};
