//https://leetcode.com/problems/alice-and-bob-playing-flower-game/description/?envType=daily-question&envId=2025-08-29


class Solution {
public:
    long long flowerGame(int n, int m) {
        //no. of odd conditions
        // one odd and other be even
        
        // no. of odd and even in m
        long int evenM;
        evenM=m/2;
        long int oddM=m-evenM;

        // no. of odd and even in n
        long int evenN;
        evenN=n/2;
        long int oddN=n-evenN;

        long long count=0;
        count=evenM*oddN + evenN*oddM;
        return count;

    }
};
