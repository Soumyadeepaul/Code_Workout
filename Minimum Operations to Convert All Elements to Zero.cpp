//https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/description/?envType=daily-question&envId=2025-11-10

class Solution {
public:
    int minOperations(vector<int>& nums) {
        // monotonic stack
        stack<int> s;
        int count=0;
        for(int i:nums){
            while(!s.empty() && s.top()>i){
                s.pop();
            }
            if(i>0 && (s.empty()||i!=s.top())){
                count++;
                s.push(i);
            }
        }
        return count;
    }
};
