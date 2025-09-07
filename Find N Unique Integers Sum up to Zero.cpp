//https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/description/?envType=daily-question&envId=2025-09-07


class Solution {
public:
    void zero(int n, deque<int> &result){
        int i=1;
        while (n!=0){
            result.push_front(-i);
            result.push_back(i);
            i++;
            n--;
            n--;
        }
    }
    vector<int> sumZero(int n) {
        deque<int> result;
        if(n&1){ //odd
            result.push_back(0);
            n--;
            zero(n,result);
        }
        else{
            zero(n,result);
        }
        vector<int> answer;
        while(!result.empty()){
            answer.push_back(result.front());
            result.pop_front();
        }
        return answer;
    }
};
