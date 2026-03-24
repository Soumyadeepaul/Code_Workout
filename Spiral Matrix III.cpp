//https://leetcode.com/problems/spiral-matrix-iii/description/


class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int left=1,down=0, right=0,up=0;
        int nleft=1,ndown=1, nright=2,nup=2;
        vector<vector<int>> result={{rStart,cStart}};
        int totalLength=rows*cols;
        int step=1;
        int x=rStart,y=cStart;
        while(step<totalLength){
            if(left!=0){
                nleft=2+left;
                for(int i=0;i<left;i++){
                    y=y+1;
                    if(y<cols && x<rows && x>-1 && y>-1 && step<totalLength){
                        result.push_back({x,y});
                        step++;
                    }
                }
                left=0;
                down=ndown;
            }
            else if(down!=0){
                ndown=2+down;
                for(int i=0;i<down;i++){
                    x=x+1;
                    
                    if(y<cols && x<rows && x>-1 && y>-1 && step<totalLength){
                        result.push_back({x,y});
                        step++;
                    }
                }
                down=0;
                right=nright;
            }
            else if(right!=0){
                nright=right+2;
                for(int i=0;i<right;i++){
                    y=y-1;
                    if(y<cols && x<rows && x>-1 && y>-1 && step<totalLength)
                    {
                        result.push_back({x,y});
                        step++;
                    }
                }
                right=0;
                up=nup;
            }
            else{
                nup=up+2;
                for(int i=0;i<up;i++){
                    x=x-1;
                    if(y<cols && x<rows && x>-1 && y>-1 && step<totalLength){
                        result.push_back({x,y});
                        step++;
                    }
                }
                up=0;
                left=nleft;
            }
        }
        return result;
    }
};
