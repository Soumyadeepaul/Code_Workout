//https://leetcode.com/problems/longest-string-chain/description/


class Solution {
public:
    bool check(string &a, string &b){
        int i=0, j=0, la=a.size(), lb=b.size();
        if(la+1!=lb) return false;

        int skip=0;
        while(i<la && j<lb){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else if(skip==0) {
                skip=1;
                j++;
            }
            else return false;
        }
        return true;
    }

    vector<int> dp;
    int result=0;
    int helper(vector<string>& words, int idx){
        if(idx==words.size()) return 0;
        if(dp[idx]!=0) return dp[idx];
        helper(words,idx+1);
        for(int i=idx+1;i<words.size();i++){
            if(check(words[idx],words[i])) {
                dp[idx]=max(dp[idx],1+helper(words,i));
            }
        }
        result=max(result,dp[idx]);
        return dp[idx];
    }


    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &a,const string &b){
            return a.size()<b.size();
        });

        dp.resize(words.size(),0);
        helper(words,0);
        return result+1; // 1 for the starting element
    }
};
