//https://leetcode.com/problems/words-within-two-edits-of-dictionary/description/


//actual logic
//insertion and deletion was not req.
// just check for sub. just by traversing

class Solution {
public:
    bool editD(string &q,string &d,vector<vector<int>> &dp){
        int l1=q.size();
        for(int i=1;i<l1+1;i++){
            for(int j=1;j<l1+1;j++){
                if(q[i-1]==d[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                }
            }
        }
        if(dp[l1][l1]<=2) return true;
        return false;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        int l1=queries[0].size();
        vector<vector<int>> dp(l1+1,vector<int> (l1+1,0));  //l1==l2 given
        vector<vector<int>> dummy(l1+1,vector<int> (l1+1,0));
        for(int i=0;i<l1+1;i++){
            dp[i][0]=i;
            dp[0][i]=i;
        }
        dummy=dp;
        for(string q:queries){
            for(string d:dictionary){
                if(editD(q,d,dp)){
                    result.push_back(q);
                    break;
                }
                dp=dummy;
            }
        }
        return result;
    }
};
