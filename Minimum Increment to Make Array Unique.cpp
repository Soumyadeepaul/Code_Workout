//https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/


class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        vector<bool>dp(pow(10,5)+1000,0);
        vector<int> left;
        for(int i:nums){
            if(dp[i]==0) dp[i]=1;
            else left.emplace_back(i);
        }
        sort(left.begin(),left.end());
        queue<int> l(left.begin(),left.end());
        left.clear();
        queue<int> vacent;
        for(int i=0;i<dp.size();i++){
            if(dp[i]==0)vacent.emplace(i); 
        }
        dp.clear();
        int count=0;

        while(!l.empty()){
            int curr=l.front();
            l.pop();
            while(curr>=vacent.front()){
                vacent.pop();
            }
            count+=vacent.front()-curr;
            vacent.pop();
        }
        return count;
    }
};
