//https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/description/?envType=daily-question&envId=2026-03-20


class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        vector<vector<int>> result;
        int rows=grid.size(),cols=grid[0].size();
        for(int r=0;r<=rows-k;r+=1){
            vector<int> ans;
            for(int c=0;c<=cols-k;c+=1){
                set<int> store;
                for(int i=r;i<r+k;i++){
                    for(int j=c;j<c+k;j++){
                        store.insert(grid[i][j]);
                    }
                }
                auto prev=store.begin();
                int val=1e9;
                for(auto it=store.begin();it!=store.end();++it){
                    if(prev==it) continue;
                    val=min(val,abs(*prev-*it));
                    prev=it;
                }
                if(val==1e9) val=0;
                ans.push_back(val);
                if(c+k>=cols)
                    result.push_back(ans); 
                
            }
        }
        return result;
    }
};
