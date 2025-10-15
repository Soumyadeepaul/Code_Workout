//https://leetcode.com/problems/top-k-frequent-words/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;

        // Count frequencies
        for (auto &w : words)
            freq[w]++;

        // Custom comparator for sorting
        auto cmp = [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second == b.second)
                return a.first < b.first;     // Lexicographically smaller first
            return a.second > b.second;       // Higher frequency first
        };

        // Move map to vector
        vector<pair<string, int>> vec(freq.begin(), freq.end());

        // Sort using custom comparator
        sort(vec.begin(), vec.end(), cmp);

        // Collect top k
        vector<string> result;
        for (int i = 0; i < k && i < vec.size(); i++)
            result.push_back(vec[i].first);

        return result;
    }
};
