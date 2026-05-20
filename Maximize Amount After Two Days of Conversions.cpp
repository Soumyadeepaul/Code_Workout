//https://leetcode.com/problems/maximize-amount-after-two-days-of-conversions/description/


class Solution {
public:

    double result = 1.0;

    void dfs(
        string &initialCurrency,
        string currency,
        unordered_map<string, unordered_map<string,double>> &day1,
        unordered_map<string, unordered_map<string,double>> &day2,
        int day,
        double rate,
        unordered_set<string> &vis1,
        unordered_set<string> &vis2
    ) {

        if(day == 3) {

            if(currency == initialCurrency) {
                result = max(result, rate);
            }

            return;
        }

        // no conversion, move to next day
        dfs(initialCurrency,
            currency,
            day1,
            day2,
            day + 1,
            rate,
            vis1,
            vis2);

        if(day == 1) {

            vis1.insert(currency);

            for(auto &p : day1[currency]) {

                if(vis1.count(p.first)) continue;

                // stay on same day
                dfs(initialCurrency,
                    p.first,
                    day1,
                    day2,
                    day,
                    rate * p.second,
                    vis1,
                    vis2);

                // move to next day
                dfs(initialCurrency,
                    p.first,
                    day1,
                    day2,
                    day + 1,
                    rate * p.second,
                    vis1,
                    vis2);
            }

            vis1.erase(currency);
        }
        else {

            vis2.insert(currency);

            for(auto &p : day2[currency]) {

                if(vis2.count(p.first)) continue;

                // stay on same day
                dfs(initialCurrency,
                    p.first,
                    day1,
                    day2,
                    day,
                    rate * p.second,
                    vis1,
                    vis2);

                // move to next day
                dfs(initialCurrency,
                    p.first,
                    day1,
                    day2,
                    day + 1,
                    rate * p.second,
                    vis1,
                    vis2);
            }

            vis2.erase(currency);
        }
    }

    double maxAmount(
        string initialCurrency,
        vector<vector<string>>& pairs1,
        vector<double>& rates1,
        vector<vector<string>>& pairs2,
        vector<double>& rates2
    ) {

        unordered_map<string, unordered_map<string,double>> day1;
        unordered_map<string, unordered_map<string,double>> day2;

        for(int i = 0; i < pairs1.size(); i++) {

            day1[pairs1[i][0]][pairs1[i][1]] = rates1[i];
            day1[pairs1[i][1]][pairs1[i][0]] = 1.0 / rates1[i];
        }

        for(int i = 0; i < pairs2.size(); i++) {

            day2[pairs2[i][0]][pairs2[i][1]] = rates2[i];
            day2[pairs2[i][1]][pairs2[i][0]] = 1.0 / rates2[i];
        }

        unordered_set<string> vis1, vis2;

        dfs(initialCurrency,
            initialCurrency,
            day1,
            day2,
            1,
            1.0,
            vis1,
            vis2);

        return result;
    }
};
