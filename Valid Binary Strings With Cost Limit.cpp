//https://leetcode.com/problems/valid-binary-strings-with-cost-limit/description/


class Solution {
public:
    vector<string> result;
    void helper(int &n, int &k, string s, int summ, int idx, bool prev){
        if(idx==n){
            if(summ<=k) result.push_back(s);
            return;
        }
        helper(n,k,s+'0',summ,idx+1, false);
        if(prev==false) helper(n,k,s+'1',summ+idx,idx+1, true);
    }
    vector<string> generateValidStrings(int n, int k) {
        helper(n,k,"",0,0, false);
        return result;
    }
};
