//https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/?envType=problem-list-v2&envId=recursion


class Solution {
public:
    void helper(vector<int> &seat,int &k, int &idx, int &n){
        if(seat.size()==1) return;
        // int count=0;
        // while(count!=k-1){
        //     idx=(++idx)%n;
        //     count++;
        // }
        idx=(idx+k-1)%n;
        seat.erase(seat.begin()+idx);
        n--;
        helper(seat,k,idx,n);
    }
    int findTheWinner(int n, int k) {
        vector<int> seat;
        for(int i=0;i<n;i++) seat.push_back(i);
        int idx=0;
        helper(seat,k,idx, n);
        return seat[0]+1;
    }
};
