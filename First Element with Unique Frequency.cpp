//https://leetcode.com/problems/first-element-with-unique-frequency/description/


class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i:nums) map[i]++;
        unordered_map<int,int> store;

        for(auto i:map) store[i.second]++;

        set<int> canBe;
        for(auto i:store){
            if(i.second==1) canBe.insert(i.first);
        }
        for(int i:nums){
            if(canBe.count(map[i])) return i;
        }

        return -1;
        
    }
};
