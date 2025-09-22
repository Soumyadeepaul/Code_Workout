//https://leetcode.com/problems/count-elements-with-maximum-frequency/description/?envType=daily-question&envId=2025-09-22


class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> map;
        int maxi=0;
        int count;
        int l=nums.size();
        for(int i=0;i<l;i++){
            map[nums[i]]++;
            if(maxi<map[nums[i]]){
                maxi=map[nums[i]];
                count=maxi;
            }
            else if(maxi==map[nums[i]]){
                count+=maxi;
            }
        }   
        return count;
    }
};
