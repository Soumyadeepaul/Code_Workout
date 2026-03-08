//https://leetcode.com/problems/find-unique-binary-string/description/?envType=daily-question&envId=2026-03-08

class Solution {
public:
    void generate(vector<string>& store, string s, int &l){
        if(s.size()==l){
            store.push_back(s);
            return;
        }
        generate(store,s+'0',l);
        generate(store,s+'1',l);
    }
    string findDifferentBinaryString(vector<string>& nums) {
        vector<string> store;
        int l=nums[0].size();
        generate(store,"",l);
        set<string> find(nums.begin(),nums.end());
        for(string s:store){
            if(!find.count(s)) return s;
        }
        return "";
    }
};
