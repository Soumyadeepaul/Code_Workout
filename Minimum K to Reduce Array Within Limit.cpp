//https://leetcode.com/contest/biweekly-contest-175/problems/minimum-k-to-reduce-array-within-limit/description/


class Solution {
public:
    bool check(vector<int>& nums, int &k){
        int count=0, square=pow(k,2);
        for(int i:nums){
            if(i%k==0) count+=(i/k);
            else count+=(i/k)+1;
            if(count>square) return false;
        }
        return true;
    }
    int minimumK(vector<int>& nums) {
        //bs
        int start=1;
        int end=10000;
        int ans=-1;
        while(start<=end){
            int mid=start+((end-start)/2);
            if(check(nums,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
        
    }
};
