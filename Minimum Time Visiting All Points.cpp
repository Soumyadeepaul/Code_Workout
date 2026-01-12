//https://leetcode.com/problems/minimum-time-visiting-all-points/description/?envType=daily-question&envId=2026-01-12


class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int val=sqrt(2);
        int result=0;
        for(int i=0;i<points.size()-1;i++){
            int x=abs(points[i+1][0]-points[i][0]);
            int y=abs(points[i+1][1]-points[i][1]);
            if(x==y) result+=(x*val);
            else{
                result+=(min(x,y)*val)+(abs(x-y));
            }
        }
        return result;
    }
};
