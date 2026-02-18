//https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/


class Solution {
public:
    int result=0;
    void helper(vector<string>& arr, int idx, string &store, vector<int> & alpha){
        result=max(result,(int)size(store));
        if(idx==arr.size()){
            return;
        }
        for(int i=idx;i<arr.size();i++){
            //check
            string prev=store;
            bool breakIt=0;
            vector<int> backUp(alpha.begin(),alpha.end());
            for(char c : arr[i]){
                if(alpha[c-'a']==1){
                    breakIt=1;
                    break;
                }
                alpha[c-'a']=1;
            }
            if(breakIt==0){
                store+=arr[i];
                helper(arr,i+1,store, alpha);
                store=prev;
            }
            for(int i=0;i<26;i++){
                alpha[i]=backUp[i];
            }
        }
        helper(arr,idx+1,store, alpha);

    }
    int maxLength(vector<string>& arr) {
        string store="";
        vector<int> alpha(26,0);
        helper(arr,0,store,alpha);
        return result;
    }
};
