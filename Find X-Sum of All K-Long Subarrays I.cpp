//https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/description/?envType=daily-question&envId=2025-11-04

class Solution {
public:

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int m=0;
        int y=k;
        vector<int> result;
        while(y<=nums.size()){
            unordered_map<int,int> map;
            for(int i=m;i<y;i++){
                map[nums[i]]++;
            }
            priority_queue<pair<int,int>> q;
            for( auto pair: map){
                q.push({pair.second,pair.first});
            }
            int score=0;
            int i=0;
            while(!q.empty()&&i!=x){
                pair<int,int> t=q.top();
                q.pop();
                score+=(t.first*t.second);
                i++;
            }
            y++;
            m++;
            result.push_back(score);
        }
        return result;
    }
};
