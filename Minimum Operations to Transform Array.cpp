//https://leetcode.com/contest/biweekly-contest-168/problems/minimum-operations-to-transform-array/description/


class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int last_element=nums2[nums2.size()-1];
        //closest diff at initial
        int idx=0;
        int diff=INT_MAX;
        int old=0;
        bool oldTobeUsed=true;
        for(int i=0;i<nums1.size();i++){
            if(abs(nums1[i]-last_element)<diff){
                diff=abs(nums1[i]-last_element);
                idx=i;
            }
        }
        old=nums1[idx];
        // perform rest of the opertion except append
        long long opCount=0;
        bool found=false;
        for(int i=0;i<nums1.size();i++){
            opCount+=abs(nums1[i]-nums2[i]);
            if((nums1[i]>=last_element && nums2[i]<=last_element)||(nums1[i]<=last_element && nums2[i]>=last_element)){
                found=true;  //found while performing operations
            }
            nums1[i]=nums2[i];
        }
        opCount++; //append
        if(found==true){
            return opCount;
        }
        // now again search for closest diff
        for(int i=0;i<nums1.size();i++){
            if(abs(nums1[i]-last_element)<diff){
                diff=abs(nums1[i]-last_element);
                idx=i;
                oldTobeUsed=false;
            }
        }
        if(oldTobeUsed==false){
            old=nums1[idx];
        }
        
        if(old!=last_element){
            opCount+=abs(old-last_element);
        }
        return opCount;
    }
};©leetcode
