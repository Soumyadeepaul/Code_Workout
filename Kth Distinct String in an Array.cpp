//https://leetcode.com/problems/kth-distinct-string-in-an-array/

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        vector<string> result;
        unordered_set<string> remove;
        for(string s:arr){
            auto it=find(result.begin(),result.end(),s);
            if(it==result.end())result.push_back(s);
            else {
                remove.insert(s);
            }
        }
        for(string s:remove){
            auto it=find(result.begin(),result.end(),s);
            result.erase(it); 
        }
        for(string i:result){
            k--;
            if(k==0) return i;
        }
        return "";
    }
};
