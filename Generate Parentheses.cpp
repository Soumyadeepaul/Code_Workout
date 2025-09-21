//https://leetcode.com/problems/generate-parentheses/description/?envType=study-plan-v2&envId=top-interview-150


class Solution {
public:
    void gen(int &n, int countOpen, int countClose,string s,vector<string> &result){
        if(countClose==n){
            result.push_back(s);
            return;
            
        }
        if(countOpen<n){
            gen(n,countOpen+1,countClose,s+"(",result);
        }
        if(countOpen>countClose){
            gen(n,countOpen,countClose+1,s+")",result);
        }
        

    }
    vector<string> generateParenthesis(int n) {
        int count=0;
        string s;
        vector<string> result;
        gen(n,0,0,s,result);
        return result;
    }
};
