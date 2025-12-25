//https://leetcode.com/problems/maximize-happiness-of-selected-children/description/?envType=daily-question&envId=2025-12-25


class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int terms=0;
        priority_queue<int> pq(happiness.begin(),happiness.end());
        long long result=0;
        int top;
        while(terms!=k){
            top=pq.top();
            pq.pop();
            if(top-terms<=0) break; 
            result=(long long) result+top-terms++;
        }
        return result;
    }
};
