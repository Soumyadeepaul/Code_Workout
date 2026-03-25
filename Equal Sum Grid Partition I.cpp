//https://leetcode.com/problems/equal-sum-grid-partition-i/description/?envType=daily-question&envId=2026-03-25


class Solution {
public:
    bool checker(vector<long long> &store){
        long long total=store[store.size()-1];
        for(int i=0;i<store.size();i++){
            if((long long)total-store[i]==store[i]) return true;
        }
        return false;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        vector<long long> store;
        int rows=grid.size(),cols=grid[0].size();
        long long summ=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                summ=(long long) summ+grid[i][j];
            }
            store.push_back(summ);
        }
        if(checker(store)) return true;
        store.clear();
        summ=0;
        for(int j=0;j<cols;j++){
            for(int i=0;i<rows;i++){
                summ=(long long) summ+grid[i][j];
            }
            store.push_back(summ);
        }
        if(checker(store)) return true;
        return false;
    }
};
