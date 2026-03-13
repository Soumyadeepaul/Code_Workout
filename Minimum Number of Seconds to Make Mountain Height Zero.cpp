//http://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/description/?envType=daily-question&envId=2026-03-13

class Solution {
public:

    // check if workers can reduce the mountain within given time
    bool check(int& mountainHeight, const vector<int>& workerTimes, long long &time){
        long long h = 0;

        for(int i : workerTimes){

            // solve: i * h(h+1)/2 <= time
            // h = floor((sqrt(1 + 8*time/i) - 1) / 2)
            long long x = (sqrt(1 + 8.0 * time / i) - 1) / 2;

            h += x;

            if(h >= mountainHeight) return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

        long long start = 1, mid;

        // worst case: slowest worker removes entire mountain
        long long end = 1LL * *max_element(workerTimes.begin(), workerTimes.end())
                        * (1LL * mountainHeight * (mountainHeight + 1) / 2);

        long long result = LLONG_MAX;

        while(start <= end){

            mid = start + (end - start) / 2;

            if(check(mountainHeight, workerTimes, mid)){
                result = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }

        return result;
    }
};
