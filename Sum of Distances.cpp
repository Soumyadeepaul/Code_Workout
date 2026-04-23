//https://leetcode.com/problems/sum-of-distances/description/?envType=daily-question&envId=2026-04-23


class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<long long>> map;
        unordered_map<int,int> idx;
        for(int i=0;i<nums.size();i++){
            if(map.count(nums[i])) map[nums[i]].push_back((long long)i+map[nums[i]][map[nums[i]].size()-1]);
            else map[nums[i]].push_back(i);
            idx[nums[i]]=0;
        }
        vector<long long> result(nums.size());
        for(int i=0;i<nums.size();i++){
            vector<long long> &temp=map[nums[i]];
            int j=idx[nums[i]]++;
            long long left=map[nums[i]][j]-i;
            long long right=map[nums[i]][map[nums[i]].size()-1]-left;
            long long lefttotal=1ll*i*j;
            long long righttotal=1ll*i*(map[nums[i]].size()-j);
            result[i]=(long long)abs(lefttotal-left)+abs(righttotal-right);
        }
        return result;
    }
};

// 0 2 3
