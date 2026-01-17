//https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/description/?envType=daily-question&envId=2026-01-17

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        vector<vector<int>> store;
        for(int i=0;i<bottomLeft.size();i++){
            store.push_back({bottomLeft[i][0],bottomLeft[i][1],topRight[i][0],topRight[i][1]});
        }
        sort(store.begin(),store.end());
        int i=1;
        
        long long result=0;
        int l=store.size();
        for(int i=0;i<l;i++){
            int ending=store[i][2];
            for(int j=i+1;j<l;j++){
                if(ending<store[i][0]){ //seperated
                    break;
                }
                int x=max(store[j][1],store[i][1]);
                int y=min(store[j][3],store[i][3]);
                if(y-x<=0){}
                else{
                    int yLen=y-x;
                    x=max(store[j][0],store[i][0]);
                    y=min(store[j][2],store[i][2]);
                    if(y-x<=0){continue;}
                    int xLen=y-x;
                    result=max(result,min(xLen,yLen)*1LL*min(xLen,yLen));
                }
            }
        }
        return result;
    }
};
