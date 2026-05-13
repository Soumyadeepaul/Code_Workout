//https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/


class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> bucket;
        string result="";
        vector<int> storeOpen;
        int currentIdx=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==')' || s[i]=='('){
                if(bucket.empty()){
                    if(s[i]==')'){}
                    else{
                        result+=s[i];
                        bucket.push(s[i]);
                        storeOpen.push_back(currentIdx++);
                    }
                }
                else{
                    if(s[i]=='('){
                        result+=s[i];
                        bucket.push(s[i]);
                        storeOpen.push_back(currentIdx++);
                    }
                    else{
                        char temp=bucket.top();
                        bucket.pop();
                        result+=s[i];
                        currentIdx++;
                    }
                }
            }
            else{//character
                result+=s[i];
                currentIdx++;
            }
        }
        int stackLength=bucket.size();
        for(int i=storeOpen.size()-1;i>=0;i--){
            if(stackLength>0){
                result.erase(storeOpen[i],1);
                stackLength--;
            }
            else break;
        }
        return result;
    }
};
