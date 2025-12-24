//https://leetcode.com/problems/apple-redistribution-into-boxes/?envType=daily-question&envId=2025-12-24

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total=accumulate(apple.begin(),apple.end(),0);
        priority_queue<int> cap(capacity.begin(),capacity.end());
        int count=0;
        while(!cap.empty() && total>0){
            total-=cap.top();
            cap.pop();
            count++;
        }
        return count;
    }
};
