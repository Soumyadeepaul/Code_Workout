//https://leetcode.com/contest/weekly-contest-476/problems/minimum-string-length-after-balanced-removals/description/
class Solution {
public:
    int minLengthAfterRemovals(string s) {
        pair<int,int> p={0,0};
        for(char i:s){
            if (i=='a') p.first++;
            else p.second++;
        }
        if(p.first==p.second) return 0;
        else return abs(p.first-p.second);
    }
}
