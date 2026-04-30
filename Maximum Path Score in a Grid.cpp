//https://leetcode.com/problems/maximum-path-score-in-a-grid/description/?envType=daily-question&envId=2026-04-30


class Solution {
public:
    // int result=-1;
    // void helper(vector<vector<int>>& grid, int k,int i,int j, int score, int cost){
    //     if(i<grid.size() && j<grid[0].size()){
    //         score+=grid[i][j];
    //         cost+=(grid[i][j]==0)? 0:1;
    //         if(cost>k) return;
    //         if(i==grid.size()-1 && j==grid[0].size()-1) result=max(result,score);
    //         helper(grid,k,i+1,j,score,cost);
    //         helper(grid,k,i,j+1,score,cost);
    //     }
    // }
    // int maxPathScore(vector<vector<int>>& grid, int k) {
    //     int score=0,cost=0;
    //     helper(grid,k,0,0,score,cost);
    //     return result;
    // }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int r=grid.size(),c=grid[0].size();
        vector<vector<vector<int>>> score_cost(r,vector<vector<int>> (c,vector<int>(k+1,-1)));

        for(int i=r-1;i>-1;i--){
            for(int j=c-1;j>-1;j--){
                if(i==r-1 && j==c-1){
                    int score=grid[i][j];
                    int cost=(grid[i][j]==0)? 0:1;
                    if(cost<k+1)
                    score_cost[i][j][cost]=score;
                }
                else if(i==r-1 && j!=c-1){
                    int cost=(grid[i][j]==0)? 0:1;
                    for(int x=0;x<k+1;x++){
                        if(cost+x<k+1 && score_cost[i][j+1][x]!=-1){
                            score_cost[i][j][cost+x]=max(score_cost[i][j][cost+x],score_cost[i][j+1][x]+grid[i][j]);
                        }
                    }
                }
                else if(i!=r-1 && j==c-1){
                    int cost=(grid[i][j]==0)? 0:1;
                    for(int x=0;x<k+1;x++){
                        if(cost+x<k+1 && score_cost[i+1][j][x]!=-1){
                            score_cost[i][j][cost+x]=max(score_cost[i][j][cost+x],score_cost[i+1][j][x]+grid[i][j]);
                        }
                    }
                }
                else{
                    int cost=(grid[i][j]==0)? 0:1;
                    for(int x=0;x<k+1;x++){
                        if(cost+x<k+1){
                            if(score_cost[i][j+1][x]!=-1)
                                score_cost[i][j][cost+x]=max(score_cost[i][j][cost+x],score_cost[i][j+1][x]+grid[i][j]);
                            if(score_cost[i+1][j][x]!=-1)
                                score_cost[i][j][cost+x]=max(score_cost[i][j][cost+x],score_cost[i+1][j][x]+grid[i][j]);
                            
                        }
                    }
                }
            }
        }
        vector<int> &temp=score_cost[0][0];
        return *max_element(temp.begin(),temp.end());
    }
};
