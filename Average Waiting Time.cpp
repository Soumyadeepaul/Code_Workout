//https://leetcode.com/problems/average-waiting-time/description/


class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int time=0;
        vector<int> result;
        for(auto &p:customers){
            int arrive=p[0];
            int t=p[1];
            if(time<arrive){
                time=arrive;
            }
            time+=t;
            result.push_back(time-arrive);
        }
        long long unsigned val=0;
        for(int i:result) val+=i;
        double ans=(double)val/result.size();
        return ans;
    }
};
