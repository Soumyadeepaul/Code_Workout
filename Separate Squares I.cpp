//https://leetcode.com/problems/separate-squares-i/description/?envType=daily-question&envId=2026-01-13


class Solution {
public:
    bool check(long double &mid,vector<vector<int>>& squares, long double &totalArea){
        long double cal=0;
        for(vector<int>& i:squares){
            double y=i[1];
            long double side=i[2];
            if(y+side<=mid){
                cal+=side*side;
            }
            else if(y>=mid){}
            else{
                cal+=(mid-y)*side;
            }
        }
        return cal<totalArea/2;
    }
    double separateSquares(vector<vector<int>>& squares) {
        long double low=0,high=0,totalArea=0;
        double result=1e9;
        for(vector<int>& i:squares){
            double y=i[1];
            long double side=i[2];
            totalArea+=side*side;
            high=max(high,y+side);
        }
        int count=0;
        while(high-low>=1e-6 && count<60){ // manage floating point bs
            long double mid=(low+high)/2;
            count++;
            if(check(mid,squares,totalArea)){
                low=mid;
                result=low;
            }
            else{
                high=mid;
            }
        }
        return result;
    }
};
