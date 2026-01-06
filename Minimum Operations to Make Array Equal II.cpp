//https://leetcode.com/problems/minimum-operations-to-make-array-equal-ii/description/


class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if(k==0){
            int found=1;
            for(int i=0;i<nums1.size();i++){
                if(nums1[i]!=nums2[i]){
                    found=0;
                    break;
                }
            }
            if(found==1) return 0;
            return -1;
        }
        int l=nums1.size();
        vector<int> store(l);
        long long inc=0,dec=0;
        int maxi=0;
        for(int i=0;i<l;i++){
            store[i]=nums1[i]-nums2[i];
            if(store[i]%k!=0) return -1;
            if(store[i]<0) dec+=(long long)store[i]/k;
            else if(store[i]>0) inc+=(long long)store[i]/k;   
        }
        if(-dec==inc) return inc;
        return -1;

    }
};
