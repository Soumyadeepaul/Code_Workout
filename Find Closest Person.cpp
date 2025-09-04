//https://leetcode.com/problems/find-closest-person/?envType=daily-question&envId=2025-09-04

class Solution {
public:
    int findClosest(int x, int y, int z) {
        if(abs(z-x)<abs(z-y)) return 1;
        else if(abs(z-x)>abs(z-y)) return 2;
        return 0;
    }
};
