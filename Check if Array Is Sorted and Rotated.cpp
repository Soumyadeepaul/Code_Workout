//https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

class Solution {
public:
    bool check(vector<int>& nums) {
        int l=nums.size(),j,i;
        bool found;
        for(int start=0;start<l;start++){
            i=(start+1)%l;
            found=true;
            while(i!=start){
                j=i-1;
                if(j==-1) j=l-1;
                if(nums[i]>=nums[j]){
                }
                else {found=false;
                break;}
                i++;
                i=i%l;
            }
            if(found==true) return found;
        }
        return false;
    }
};
