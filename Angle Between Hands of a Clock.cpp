//https://leetcode.com/problems/angle-between-hands-of-a-clock/description/?envType=daily-question&envId=2026-06-18


class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle=abs(60*hour-11*minutes)/2.0;
        return min(360.0-angle,angle);
    }
};
