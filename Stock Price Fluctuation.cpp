//https://leetcode.com/problems/stock-price-fluctuation/description/?envType=problem-list-v2&envId=heap-priority-queue


class StockPrice {
private:
    unordered_map<int, list<int>::iterator> mp;
    list<int> store;
    int curr = 0;
    int maxi = INT_MIN, mini = INT_MAX;

public:
    void update(int timestamp, int price) {
        int replace = 0;
        bool changed = false;

        if(mp.count(timestamp)){
            replace = *mp[timestamp];
            store.erase(mp[timestamp]);
            changed = true;
        }

        store.push_back(price);
        mp[timestamp] = prev(store.end());
        curr = max(curr, timestamp);

        maxi = max(maxi, price);
        mini = min(mini, price);

        if(changed && replace == maxi)
            maxi = *max_element(store.begin(), store.end());

        if(changed && replace == mini)
            mini = *min_element(store.begin(), store.end());
    }

    int current() {
        return *mp[curr];
    }

    int maximum() {
        return maxi;
    }

    int minimum() {
        return mini;
    }
};
