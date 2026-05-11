//https://leetcode.com/problems/separate-the-digits-in-an-array/description/?envType=daily-question&envId=2026-05-11


class Solution {
public:
    vector<int> result;
    void helper(int n){
        stack<int> s;
        while(n){
            s.push(n%10);
            n/=10;
        }
        while(!s.empty()){
            result.emplace_back(s.top());
            s.pop();
        }
    }
    vector<int> separateDigits(vector<int>& nums) {
        for(int i:nums) helper(i);
        return result;
    }
};
