//https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/?envType=daily-question&envId=2026-05-21

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> unique1(arr1.begin(),arr1.end());
        unordered_set<int> unique2(arr2.begin(),arr2.end());
        unordered_set<int> prefix;
        for(auto it=unique1.begin();it!=unique1.end();it++){
            int val=*it;
            string s=to_string(val);
            string store="";
            for (char c:s){
                store+=c;
                int temp=stoi(store);
                prefix.insert(temp);
            }
        }
        int result=0;
        for(auto it=unique2.begin();it!=unique2.end();it++){
            int val=*it;
            string s=to_string(val);
            string store="";
            for (char c:s){
                store+=c;
                int temp=stoi(store);
                if(prefix.count(temp)) result=max(result,temp);
            }
        }
        string l=to_string(result);
        if(l=="0") return 0;
        return l.size();
    }
};
