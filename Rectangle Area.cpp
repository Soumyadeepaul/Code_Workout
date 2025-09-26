//https://leetcode.com/problems/rectangle-area/description/?envType=problem-list-v2&envId=math


class Solution {
public:
    int area(int x1, int y1, int x2,int y2){
        return (x2-x1)*(y2-y1);
    }
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1;
        int area2;
        int commonArea=0;
        area1=area(ax1,ay1,ax2,ay2);
        area2=area(bx1,by1,bx2,by2);
        if(bx1>=ax2){
        }
        else if(bx2<=ax1){
        }
        else if(by1>=ay2){
        }
        else if(by2<=ay1){
        }
        else{
            commonArea=area(max(bx1,ax1),max(ay1,by1),min(bx2,ax2),min(by2,ay2));
        }
        return area1+area2-commonArea;
    }
};
