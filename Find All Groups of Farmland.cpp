//https://leetcode.com/problems/find-all-groups-of-farmland/


class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> result;
        int row=land.size();
        int col=land[0].size();
        stack<pair<int,int>> buck;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(land[i][j]==1){
                    buck.push({i,j});
                    int x=0,y=0;
                    while(!buck.empty()){
                        auto p=buck.top();
                        buck.pop();
                        land[p.first][p.second]=0;
                        x=max(x,p.first);
                        y=max(y,p.second);
                        if(p.first+1<row && land[p.first+1][p.second]==1)
                            buck.push({p.first+1,p.second});
                        if(p.second+1<col && land[p.first][p.second+1]==1)
                            buck.push({p.first,p.second+1});
                    }
                    result.push_back({i,j,x,y});

                }
            }
        }
        return result;
    }
};
