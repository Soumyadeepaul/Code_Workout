//https://leetcode.com/problems/k-closest-points-to-origin/description/?envType=problem-list-v2&envId=heap-priority-queue


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<double,vector<double>, greater<double>> pq;
        unordered_map<double,vector<vector<int>>> map;
        double dist;
        vector<vector<int>> result;
        for(vector<int> p:points){
            dist=sqrt(p[0]*p[0] + p[1]*p[1]);
            map[dist].push_back(p);
            pq.push(dist);
        }
        while(k!=0){
            double top=pq.top();
            pq.pop();
            vector<vector<int>> r=map[top];
            for(vector<int> r2:r){
                result.push_back(r2);
                if(k==0) return result;
                k--;
            }
        }
        return result;
    }
};
