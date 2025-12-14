//https://leetcode.com/contest/weekly-contest-480/problems/absolute-difference-between-maximum-and-minimum-k-elements/description/


class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        priority_queue<int> maxi(nums.begin(),nums.end());
        priority_queue<int,vector<int>,greater<int>> minn(nums.begin(),nums.end());
        int result=0;
        while(k){
            result+=maxi.top();
            maxi.pop();
            result-=minn.top();
            minn.pop();
            k--;
        }
        return result;
        
    }
};
