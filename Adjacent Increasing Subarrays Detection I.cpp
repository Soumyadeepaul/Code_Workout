//https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/description/?envType=daily-question&envId=2025-10-14

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int l=nums.size();
        int prev=nums[0];
        int count=0;
        for(int i=0;i<l-k;i++){
            bool increasing=true;
            for(int j=i+1;j<i+k;j++){
                //cout<<nums[j-1]<<" ";
                if(nums[j-1]>=nums[j]){
                    increasing=false;
                    break;
                }
            }
            //cout<<"   ";
            if(i+k+k>l) break;
            if(increasing==true){
                for(int j=i+k+1;j<i+k+k;j++){
                    //cout<<nums[j-1]<<" ";
                    if(nums[j-1]>=nums[j]){
                        increasing=false;
                        break;
                    }
                }
            }
            //cout<<"\n";
            if(increasing==true){return true;}
        }
        return false;
    }
};
