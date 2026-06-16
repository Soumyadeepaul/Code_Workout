//https://leetcode.com/problems/process-string-with-special-operations-i/description/?envType=daily-question&envId=2026-06-16


class Solution {
public:
    string processStr(string s) {
        vector<char> result;
        for(char c:s){
            if(c=='*'){
                int l=result.size();
                if(l) result.pop_back();
            }
            else if(c=='#'){
                vector<char> temp(result.begin(),result.end());
                for(int i=0;i<temp.size();i++){
                    result.push_back(temp[i]);
                }
            }
            else if(c=='%'){
                stack<char> temp(result.begin(),result.end());
                result.clear();
                while(!temp.empty()){
                    result.push_back(temp.top());
                    temp.pop();
                }
            }
            else{
                result.push_back(c);
            }
        }
        string res;
        for(char c:result) res+=c;
        return res;
    }
};
