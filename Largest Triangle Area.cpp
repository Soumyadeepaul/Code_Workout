//https://leetcode.com/problems/largest-triangle-area/description/?envType=daily-question&envId=2025-09-27


class Solution {
public:
    double area(int x1,int x2,int x3,int y1,int y2,int y3){
        double d1=(double)sqrt((pow((x2-x1),2)+pow((y2-y1),2)));
        double d2=(double)sqrt((pow((x3-x1),2)+pow((y3-y1),2)));
        double d3=(double)sqrt((pow((x2-x3),2)+pow((y2-y3),2)));
        double s=(double)(d1+d2+d3)/2;
        double a=sqrt(s*(s-d1)*(s-d2)*(s-d3));
        return a;
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea=0;
        int l=points.size();
        for(int i=0;i<l;i++){
            for(int j=i+1;j<l;j++){
                for(int k=j+1;k<l;k++){
                    maxArea=max(maxArea,area(points[i][0],points[j][0],points[k][0],points[i][1],points[j][1],points[k][1]));
                }
            }
        }
        return maxArea;
    }
};
