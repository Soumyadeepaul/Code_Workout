//https://leetcode.com/contest/weekly-contest-467/problems/earliest-time-to-finish-one-task/description/


class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(),nums.end());
        vector<int> result;
        int i=0;
        while(i!=k&&!q.empty()){
            int top=q.top();
            q.pop();
            if(i==0 || top!=result[i-1]){
                result.push_back(top);
                i++;
            }
        }
        return result;
    }
};©leetcode
