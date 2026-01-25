//https://leetcode.com/contest/weekly-contest-486/problems/rotate-non-negative-elements/description/



class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> idxes;
        int l=nums.size();
        for(int i=0;i<l;i++){
            if(nums[i]>-1) idxes.push_back(i);
        }
        vector<int> revIdx(idxes.begin(),idxes.end());
        reverse(revIdx.begin(),revIdx.end());
        vector<int> result(nums.begin(),nums.end());
        int size=idxes.size();
        if (size==0) return result;
        if(k>=size) k%=size;
        
        int track=-1; //for idx
        for(int i=0;i<l;i++){
            if(nums[i]>-1){
                track++;
                if(track-k>-1){
                    result[idxes[track-k]]=nums[i];
                }
                else{
                    result[revIdx[abs(track-k+1)]]=nums[i];
                }
            }
        }
        return result;
    }
};
