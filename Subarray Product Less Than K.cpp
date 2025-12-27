//https://leetcode.com/problems/subarray-product-less-than-k/description/?envType=problem-list-v2&envId=sliding-window


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0 || k==1) return 0;
        int count=0;
        int i=0,j=0;
        int l=nums.size();
        long long mul=1;
        int previous=0; // to delete the seq. calculated under 1 less length of i----j
        while(j!=l){
            if(mul*nums[j]<k){
                mul*=nums[j];
                j++;
                if((j-i)&1){
                    count+=(j-i)*(j-i+1)/2-previous;
                    previous=(j-i)*(j-i+1)/2;
                }
                else{
                    count+=((j-i)/2)*(j-i+1)-previous;
                    previous=((j-i)/2)*(j-i+1);
                }
            }
            else{
                while(mul*nums[j]>=k && i<j){
                    mul/=nums[i];
                    i++;
                    if(mul==0) mul=1;
                }
                if(nums[j]>=k){
                    i=++j;
                    previous=0; // i and j came in same index
                    continue;
                }
                // cout<<mul<<endl;
                mul*=nums[j];
                j++;
                previous=(j-i-1)*(j-i)/2;
                if((j-i)&1){
                    count+=(j-i)*(j-i+1)/2-previous;
                    previous=(j-i)*(j-i+1)/2;
                }
                else{
                    count+=((j-i)/2)*(j-i+1)-previous;
                    previous=((j-i)/2)*(j-i+1);
                }
            }
            // cout<<mul<<" "<<count<<endl;
        }
        return count;
    }
};
