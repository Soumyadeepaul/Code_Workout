//https://leetcode.com/problems/max-points-on-a-line/description/


class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<double,int> slope;
        int result=1;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                double s=INT_MAX;
                if(points[j][0]-points[i][0]!=0) s=(double)(points[j][1]-points[i][1])/(double)(points[j][0]-points[i][0]);
                slope[s]++;
                result=max(result,slope[s]+1);
            }
            slope.clear(); //according each point... no of points coming in same slope
        }
        return result;
    }
};
