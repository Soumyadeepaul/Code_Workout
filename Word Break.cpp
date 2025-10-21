//https://leetcode.com/problems/word-break/description/?envType=study-plan-v2&envId=top-interview-150


class Solution {
public:
    // void recursion(string &target,vector<string>& wordDict,string stack,bool &found){
    //     if(target.substr(0,stack.size())!=stack){
    //         return;
    //     }
    //     else if(stack.size()==target.size()){
    //         if(target==stack){
    //             found=true;
    //             return;
    //         }
    //         found=false;
    //         return;
    //     }
    //     else if(stack.size()>target.size()){
    //         found=false;
    //         return;
    //     }
    //     for(string i: wordDict){
    //         recursion(target,wordDict,stack+i,found);
    //         if(found==true){
    //             return;
    //         }
    //     }

    // }

    // bool wordBreak(string s, vector<string>& wordDict) {
    //     bool found=false;
    //     string stack="";
    //     recursion(s,wordDict,stack,found);
    //     return found;
    // }

    bool oneDdpApproach(string &s, unordered_set<string>& words, vector<int> &dp, int doneTill) {
        if (doneTill == s.size()) return true;

        if (dp[doneTill] != -1) return dp[doneTill];  // use memoization (both true and false)

        for (int i = doneTill; i < s.size(); i++) {
            if (words.find(s.substr(doneTill, i - doneTill + 1)) != words.end() && 
                oneDdpApproach(s, words, dp, i + 1)) {
                return dp[doneTill] = true;  // mark the starting index as true
            }
        }

        return dp[doneTill] = false; // mark failure for this index
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size() + 1, -1);  // -1 = not visited, 0 = false, 1 = true
        return oneDdpApproach(s, words, dp, 0);
    }
};
