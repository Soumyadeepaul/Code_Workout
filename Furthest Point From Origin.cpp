//https://leetcode.com/problems/furthest-point-from-origin/description/?envType=daily-question&envId=2026-04-24


class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l=0,r=0;
        int length=moves.size();
        for(auto m:moves){
            if(m=='L') l++;
            else if(m=='R') r++;
        }
        return abs(l-r)+(length-(l+r));
    }
};
