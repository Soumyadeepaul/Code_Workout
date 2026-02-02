//https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/description/?envType=daily-question&envId=2026-02-02



class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        long long result = LLONG_MAX;
        int n = nums.size();
        k -= 1;  // we want k-1 smallest

        set<pair<int,int>> sorte;   // k-1 smallest
        set<pair<int,int>> unused;  // rest
        long long tracker = 0;

        // initial window [1 ... dist+1]
        for (int i = 1; i <= dist + 1; i++) {
            pair<int,int> cur = {nums[i], i};

            if ((int)sorte.size() < k) {
                sorte.insert(cur);
                tracker += cur.first;
            } else if (!sorte.empty() && cur < *prev(sorte.end())) {
                auto it = prev(sorte.end());
                unused.insert(*it);
                tracker -= it->first;
                sorte.erase(it);

                sorte.insert(cur);
                tracker += cur.first;
            } else {
                unused.insert(cur);
            }
        }

        result = tracker + nums[0];

        // slide window
        for (int i = 2; i + dist < n; i++) {
            // remove i-1
            pair<int,int> rem = {nums[i - 1], i - 1};
            if (sorte.count(rem)) {
                sorte.erase(rem);
                tracker -= rem.first;

                if (!unused.empty()) {
                    auto it = unused.begin();
                    sorte.insert(*it);
                    tracker += it->first;
                    unused.erase(it);
                }
            } else {
                unused.erase(rem);
            }

            // add i+dist
            pair<int,int> add = {nums[i + dist], i + dist};
            if ((int)sorte.size() < k) {
                sorte.insert(add);
                tracker += add.first;
            } else if (!sorte.empty() && add < *prev(sorte.end())) {
                auto it = prev(sorte.end());
                unused.insert(*it);
                tracker -= it->first;
                sorte.erase(it);

                sorte.insert(add);
                tracker += add.first;
            } else {
                unused.insert(add);
            }

            result = min(result, tracker + nums[0]);
        }

        return result;
    }
};





/////////////////////

//TLE


class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        long long result=LLONG_MAX;
        int i=dist+1;
        set<pair<int,int>> sorte;
        set<pair<int,int>> unused;
        long long tracker=0;
        for(int j=1;j<i;j++){
            sorte.insert({nums[j],j});
            tracker+=nums[j];
        }
        int l=nums.size();
        long long summ;
        pair<int,int> sub;
        pair<int,int> add;
        pair<int,int> i_distth;
        while(i<l){
            summ=nums[0];
            sorte.insert({nums[i],i});
            tracker+=nums[i];

            while(sorte.size()>k-1){
                sub=*--sorte.end();
                unused.insert(sub);
                sorte.erase(prev(sorte.end()));
                tracker-=sub.first;
            }
            

            if(result>(long long)summ+tracker) result=(long long)summ+tracker;
            while(!unused.empty()){
                add=*unused.begin();
                sorte.insert(add);
                unused.erase(unused.begin());
                tracker+=add.first;
            }
            

            //remove i-distth index
            i_distth={nums[i-dist],i-dist};
            sorte.erase(i_distth);
            tracker-=i_distth.first;
            i++;
        }
        return result;
    }
};
