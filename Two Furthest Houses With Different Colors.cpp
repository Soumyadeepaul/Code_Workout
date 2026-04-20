//https://leetcode.com/problems/two-furthest-houses-with-different-colors/description/?envType=daily-question&envId=2026-04-20



class Solution {
public:
    int maxDistance(vector<int>& colors) {
        unordered_map<int,pair<int,int>> idx;  //color:minIdx,maxIdx
        for(int i=0;i<colors.size();i++){
            if(idx.count(colors[i])) idx[colors[i]].second=i;
            else idx[colors[i]]={i,i};
        }
        int result=-1;
        for(auto p:idx){
            for(auto q:idx){
                if(p.first!=q.first) result=max(result,abs(p.second.first-q.second.second));
            }
        }
        return result;
    }
};
