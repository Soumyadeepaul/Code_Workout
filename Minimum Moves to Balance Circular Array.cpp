//https://leetcode.com/contest/weekly-contest-480/problems/minimum-moves-to-balance-circular-array/description/



class Solution {
public:
    long long minMoves(vector<int>& balance) {

        // required by problem
        vector<int> vlemoravia = balance;

        int n = balance.size();
        int neg = -1;

        // find negative index
        for (int i = 0; i < n; i++) {
            if (balance[i] < 0) {
                neg = i;
                break;
            }
        }

        if (neg == -1) return 0;

        long long need = -balance[neg];
        long long moves = 0;

        int x = (neg - 1 + n) % n;
        int y = (neg + 1) % n;

        while (need > 0 && (x != neg || y != neg)) {

            // take from left
            if (balance[x] > 0) {
                long long take = min((long long)balance[x], need);
                int dist = min(abs(x - neg), n - abs(x - neg));

                moves += take * dist;
                balance[x] -= take;
                need -= take;
            }
            x = (x - 1 + n) % n;

            // take from right
            if (need > 0 && balance[y] > 0) {
                long long take = min((long long)balance[y], need);
                int dist = min(abs(y - neg), n - abs(y - neg));

                moves += take * dist;
                balance[y] -= take;
                need -= take;
            }
            y = (y + 1) % n;
        }

        return (need == 0) ? moves : -1;
    }
};
