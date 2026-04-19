//https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/description/?envType=daily-question&envId=2026-04-19


class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0,l1=nums1.size(),l2=nums2.size();
        reverse(nums2.begin(),nums2.end());
        int result=0;
        while(i<l1){
            auto pos=lower_bound(nums2.begin(),nums2.end(),nums1[i]);
            if(pos==nums2.end()) i++;
            else{
                j=l2-(pos-nums2.begin())-1;
                result=max(result,j-i);
                i++;
            }
        }
        return result;
    }
};
