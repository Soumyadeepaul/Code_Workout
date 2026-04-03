//https://leetcode.com/problems/minimum-speed-to-arrive-on-time/description/


class Solution {
public:
    bool check(int mid,vector<int>& dist, double hour){
        double total=0.0;
        for(int i=0;i<dist.size()-1;i++){
            // total+=(dist[i] + mid - 1) / mid;
            total+=ceil((double)dist[i]/mid);
        }
        total+=(double)dist[dist.size()-1]/mid;
        if(total<=hour) return true;
        return false;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int start=1,end=1e7,mid,result=-1;
        while(start<=end){
            mid=(start+end)/2;
            if(check(mid,dist,hour)){
                result=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return result;
    }
};
