//https://leetcode.com/problems/count-covered-buildings/description/?envType=daily-question&envId=2025-12-11


class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,pair<int,int>> map_x;   // the bilding shouldnt be the at starting or ending
        unordered_map<int,pair<int,int>> map_y;   // should not be left or right most
        int count=0;
        for(auto i:buildings){
            if(map_x.count(i[0])){}
            else map_x[i[0]].first=INT_MAX;
            map_x[i[0]].first=min(map_x[i[0]].first,i[1]);
            map_x[i[0]].second=max(map_x[i[0]].second,i[1]);
            if(map_y.count(i[1])){}
            else map_y[i[1]].first=INT_MAX;
            map_y[i[1]].first=min(map_y[i[1]].first,i[0]);
            map_y[i[1]].second=max(map_y[i[1]].second,i[0]);

        }
        for(auto i:buildings){
            if(map_x[i[0]].first==i[1] || map_y[i[1]].first==i[0]) continue;
            if(map_x[i[0]].second==i[1] || map_y[i[1]].second==i[0]) continue;
            count++;
        }
        return count;
    }
};
