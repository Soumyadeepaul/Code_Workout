//https://leetcode.com/contest/weekly-contest-479/problems/sort-integers-by-binary-reflection/description/

class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        vector<pair<int,int>> store;
        for(int n:nums){
            int temp=n;
            int s=0;
            while(temp){
                int rem=temp%2;
                temp/=2;
                s=s*2+rem;
            }
            store.push_back({s,n});
        }
        sort(store.begin(),store.end());
        vector<int> result;
        for(auto s:store){
            result.push_back(s.second);
        }
        return result;
    }
};
