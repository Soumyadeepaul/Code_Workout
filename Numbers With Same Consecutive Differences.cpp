//https://leetcode.com/problems/numbers-with-same-consecutive-differences/description/



class Solution {
public:
    void helper(int &n, int &k, int l, vector<int> &result, string num){
        if(l==n){
            result.push_back(stoi(num));
            return;
        }
        if(l!=0){
            if(num[l-1]-'0'-k>-1) {
                helper(n,k,l+1,result,num+to_string(num[l-1]-'0'-k));
            }
            if(num[l-1]-'0'+k<10 && k!=0){
                helper(n,k,l+1,result,num+to_string(num[l-1]-'0'+k));
            }
        }
        else{
            for(int i=1;i<10;i++){
                helper(n,k,l+1,result,num+to_string(i));
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> result;
        helper(n,k,0,result,"");
        return result;
    }
};
