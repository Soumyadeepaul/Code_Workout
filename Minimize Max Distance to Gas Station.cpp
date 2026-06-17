//https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1


class Solution {
  public:
    double minMaxDist(vector<int> &stations, int K) {
        // Code here
        if(stations.size()<=1) return 0.00;
        vector<int> count(stations.size(),0);
        priority_queue<vector<double>> pq;
        for(int i=0;i<stations.size()-1;i++){
            pq.push({stations[i+1]-stations[i],i});
        }
        
        while(K>0){
            auto top=pq.top();
            pq.pop();
            double divisor=2.0+count[(int)top[1]];
            int initialDif=stations[top[1]+1]-stations[top[1]];
            double mid=initialDif/divisor;
            pq.push({mid,top[1]});
            count[top[1]]++;
            K--;
            
        }
        auto top=pq.top();
        return top[0];
    }
};
