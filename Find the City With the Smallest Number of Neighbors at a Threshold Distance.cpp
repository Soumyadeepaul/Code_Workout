//https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/


class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //floyd ALGO
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        int x,y,d;
        int node;
        for(int i=0;i<edges.size();i++){
            x=edges[i][0];
            y=edges[i][1];
            d=edges[i][2];
            if(d<=distanceThreshold){
                dp[x][y]=d;
                dp[y][x]=d;
            }
            
        }
        for(int i=0;i<n;i++){
            dp[i][i]=0;
        }
        for(int i=0;i<n;i++){
            for(int x=0;x<n;x++){
                for(int y=0;y<n;y++){
                    long long cal=(long long)dp[x][i]+dp[i][y];
                    if(cal<=distanceThreshold){
                        if(cal<dp[x][y])
                            dp[x][y]=cal;
                    }
                }
            }
        }
        int minnNeighbour=INT_MAX;
            
        int count;
        for(int i=0;i<n;i++){
            count=0;
            for(int j=0;j<n;j++){
                if(dp[i][j]!=INT_MAX){count++;}
            }
            if(count<=minnNeighbour){
                node=i;
                minnNeighbour=count;
            }
        }
        return node;
    }
};
