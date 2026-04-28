//https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/description/?envType=daily-question&envId=2026-04-28


class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> median;
        for(auto g:grid){
            for(int i:g) median.emplace_back(i);
        }
        sort(median.begin(),median.end());
        int l=median.size();
        int mid=l/2;
        int medianElement=median[mid];
        int count=0;
        for(auto g:grid){
            for(int i:g){
                if(abs(medianElement-i)%x == 0) count+=abs(medianElement-i)/x;
                else return -1; 
            }
        }
        return count;
    }
};
