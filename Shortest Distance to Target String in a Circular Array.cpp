//https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/description/?envType=daily-question&envId=2026-04-15


class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        unordered_map<string,vector<int>> map;
        for(int i=0;i<words.size();i++){
            map[words[i]].push_back(i);
        }
        if(!map.count(target)) return -1;
        vector<int> idx=map[target];
        vector<int> directDistance;
        int result=1e9+7;
        for(int i:idx){
            directDistance.push_back(abs(startIndex-i));
            result=min(result,abs(startIndex-i));
        }
        int l=words.size();
        for(int i:directDistance) result=min(result,l-i);
        return result;
    }
};
