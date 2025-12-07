//https://leetcode.com/contest/weekly-contest-479/problems/largest-prime-from-consecutive-prime-sum/description/


class Solution {
public:
    int largestPrime(int n) {
        if (n < 2) return 0;

        // 1. Sieve of Eratosthenes
        vector<int> prime(n + 1, 1);
        prime[0] = 0;
        prime[1] = 0;

        for (int i = 2; i * i <= n; ++i) {
            if (prime[i] == 0) continue;
            for (int j = i * i; j <= n; j += i) {
                prime[j] = 0;
            }
        }

        // 2. Track prefix sums of primes and last 5 sums
        long long summ = 0;
        int result = 0;

        queue<long long> store;              // last 5 sums
        unordered_set<long long> inStore;    // fast membership

        for (int i = 2; i <= n; ++i) {
            if (prime[i] == 0) continue;     // skip non-primes

            summ += i;                       // prefix sum of primes

            // push new sum
            store.push(summ);
            inStore.insert(summ);

            // keep only last 5
            if (store.size() > 5) {
                long long old = store.front();
                store.pop();
                inStore.erase(old);
            }

            // if current prime equals one of the last 5 sums
            if (inStore.count(i)) {
                result = i;
            }
        }

        return result;
    }
};
