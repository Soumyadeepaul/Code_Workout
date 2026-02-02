//https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating/description/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;

        unordered_map<int,int> even, odd;

        // frequency count
        for(int i = 0; i < n; i++){
            if(i % 2 == 0) even[nums[i]]++;
            else odd[nums[i]]++;
        }

        // get top 2 frequencies
        auto getTop2 = [&](unordered_map<int,int>& mp){
            pair<int,int> first = {0,0}, second = {0,0};
            for(auto &p : mp){
                if(p.second > first.second){
                    second = first;
                    first = p;
                }
                else if(p.second > second.second){
                    second = p;
                }
            }
            return vector<pair<int,int>>{first, second};
        };

        auto e = getTop2(even); // {value, count}
        auto o = getTop2(odd);

        int evenCount = (n + 1) / 2;
        int oddCount  = n / 2;

        // no conflict
        if(e[0].first != o[0].first){
            return (evenCount - e[0].second) + (oddCount - o[0].second);
        }

        // conflict: same value chosen
        int option1 = (evenCount - e[0].second) + (oddCount - o[1].second);
        int option2 = (evenCount - e[1].second) + (oddCount - o[0].second);

        return min(option1, option2);
    }
};
