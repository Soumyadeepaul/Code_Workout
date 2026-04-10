//https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/description/?envType=daily-question&envId=2026-04-10


class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]].push_back(i);
        }
        int result=1e9+7;
        for(auto p:map){
            if(p.second.size()>=3){
                vector<int> x=p.second;
                for(int i=0;i<x.size()-2;i++){
                    result=min(result,abs(x[i]-x[i+1])+abs(x[i+1]-x[i+2])+abs(x[i+2]-x[i]));
                }
                
            }
        }
        return (result==(1e9+7))? -1:result;
    }
};
