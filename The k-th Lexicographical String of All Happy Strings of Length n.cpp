//https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/?envType=daily-question&envId=2026-03-14


class Solution {
public:
    vector<char> store={'a','b','c'};
    set<string> result;
    void helper(int &n,int &k, string s, char prev){
        if(result.size()==k) return;
        if(s.size()==n){
            result.insert(s);
            return;
        }
        for(char i:store){
            if(i!=prev) helper(n,k,s+i,i);
        }
    }
    string getHappyString(int n, int k) {
        string s="";
        helper(n,k,s,'-1');
        vector<string> r(result.begin(),result.end());
        if(r.size()<k) return "";
        return r[k-1];
    }
};
