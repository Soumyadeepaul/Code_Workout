//https://leetcode.com/problems/count-square-sum-triples/description/?envType=daily-question&envId=2025-12-08


class Solution {
public:
    int countTriples(int n) {
        unordered_set<int> store;
        vector<int> v;
        for(int i=0;i<=n;i++){
            int p=pow(i,2);
            store.insert(p);
            v.push_back(p);
        }
        int count=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(store.find(v[i]+v[j])!=store.end()) count+=2;
            }
        }
        return count;
    }
};
